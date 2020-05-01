#include "ProcessHandler.h"
#include "SearchJson.h"
#include "UniBit.h"
#include "main.h"

void process()
{
    ActiveAlgorithm active;
    active.registerWork("Instruments");
    active.registerWork("InstrumentsMeta");
    active.run();
    active.endWork();
}

static std::vector<std::string> split(std::string &input, char delim)
{
    std::stringstream m_stream(input);
    std::vector<std::string> seglist;
    std::string segment;
    seglist.reserve(50);
    seglist.clear();

    while(std::getline(m_stream, segment, delim))
    {
        seglist.push_back(std::move(segment));
    }
    return seglist;
}

static std::optional<std::string> print(std::string& param)
{
    std::string update = "update - Update reference lists for a certain exchange\n";
    update.append("E.g. 'update OMX' or 'update NASDAQ'\n\n");

    std::string help = "help - Print help text\n";
    help.append("E.g. 'help update' or 'help search'\n\n");

    std::string search = "search - Search for stock symbols and company name\n";
    search.append("E.g. 'search OMX Veoneer' or 'search OMX VNE-SDB'\n");
    search.append("E.g. 'search NASDAQ Microsoft' or 'search NASDAQ MSFT'\n\n");

    std::string indicator = "<stock indicator> <stock symbol> <parameters>\n";
    indicator.append("E.g. 'ADX MSFT datapoint 14'\n\n");

    if (std::string::npos != param.find("update")) {
        std::cout << update;
    }
    else if (std::string::npos != param.find("search"))
    {
        std::cout << search;
    }
    else {
        std::cout << help << search << update << indicator << std::endl;
    }
    return std::nullopt;
}

static std::optional<std::string> update(std::string& param)
{
    auto vec = split(param, ' ');
    pop_front(vec);
    std::string exchange = vec.front();
    try {
        UNIBIT::updateReferenceList(exchange);
    }
    catch(std::exception &ex) {
        std::cerr << "Error update reference list, " << "did you type a correct exchange?" << std::endl;
        std::cerr << ex.what() << std::endl;
    }
    return std::nullopt;
}

static std::optional<std::string> search(std::string &param)
{
    auto vec = split(param, ' ');
    pop_front(vec);
    std::string exchange = vec.front();
    pop_front(vec);
    std::string pattern = vec.front();
    std::string url = "../data/UNIBIT_symbols[";
    url.append(exchange).append("].json");

    boost::to_upper(pattern);
    IO::SearchJson search(url);
    std::vector<std::pair<std::string, std::string>> tmp;
    int findings = search.exists(tmp, pattern, "ticker", {"ticker", "companyName"});

    if (findings > 1)
    {
        std::string ticker;
        std::string chosenSymbol;
        std::cout << "Write ticker code: " << std::endl;
        std::cin >> ticker;
        for (const std::pair<std::string, std::string> &pair : tmp )
        {
            std::cout << " > " << pair.second << std::endl;
            if (std::string::npos != pair.first.find("ticker")) {
                chosenSymbol = pair.second;
            }
        }
        return chosenSymbol;
    }
    return std::nullopt;
}

static std::optional<std::string> compile (std::string& param)
{
    std::string temp = param;
    auto vec = split(temp, ' ');
    std::string cmd = vec.front();
    pop_front(vec);
    for (auto &s : vec) {
        temp.append(s);
        temp.append(" ");
    }

    const std::string WORK = boost::algorithm::to_upper_copy(cmd);
    ActiveAlgorithm active;
    active.registerWork(WORK);
    std::string what = active.getVal();
    std::cout << "executed " << what << std::endl;
    active.endWork();
    return std::nullopt;
}


static std::unordered_map<std::string, std::function<std::optional<std::string>(std::string&)>> cliCommands;

static void regInit() {
    cliCommands["search"] = search;
    cliCommands["update"] = update;
    cliCommands["help"] = print;
    cliCommands["ADX"] = compile;
    cliCommands["SMA"] = compile;
}

int main(int argc, char** argv)
{
    std::thread processThread (process);
    processThread.join();

    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();

    //regInit();
    if (argc < 2) {
        std::string cmd = "help";
        std::string tmp;
        cliCommands[cmd](tmp);
        return EXIT_FAILURE;
    }

    std::string cmd = argv[1];
    std::string param;
    std::stringstream ss;
    for (int i = 1; i < argc; i++) {
        ss << argv[i];
        ss << " ";
    }
    param = ss.str();
    std::optional<std::string> result = cliCommands[cmd](param);
    if (!result || !result.has_value()) {
        std::cout << "CMD OK \n\n";
        return EXIT_SUCCESS;
    }

    return 0;

}

