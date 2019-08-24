//
// Created by mjonsson on 8/24/19.
//

#include <iostream>
#include "CSVWriter.h"
using namespace IO;

std::vector<std::string> CSVWriter::getAllLines() {
    std::vector<std::string> row;
    std::string line, word, temp;
    std::fstream file;
    file.open(filename, std::ios::in);

    while (file >> temp)
    {
        getline(file, line);
        std::stringstream s(line);
        while (getline(s, word, delimeter)) {

            row.push_back(word);
        }
    }
    file.close();
    return row;
}

int CSVWriter::deleteRow(int &lineNumber)
{
    std::fstream fileIN, fileOut;
    fileIN.open(filename, std::ios::in);
    fileOut.open("tmp.csv", std::ios::out);

    int currNumber;
    bool found = false;
    std::string line, word;
    std::vector<std::string> row;

    while (!fileIN.eof()) {

        row.clear();
        getline(fileIN, line);
        std::stringstream s(line);

        while (getline(s, word, delimeter)) {
            row.push_back(word);
        }
        int row_size = row.size();
        currNumber = stoi(row[0]);

        if (currNumber != lineNumber) {
            if (!fileIN.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    fileOut << row[i] << ",";
                }
                fileOut << row[row_size - 1] << "\n";
            }
        }
        else {
            found = true;
        }
        if (fileOut.eof())
            break;
    }

    fileIN.close();
    fileOut.close();

    std::remove(filename);
    std::rename("tmp.csv", filename);
    if (found) {
        std::cout << "Row deleted\n";
        return 0;
    }
    else
        std::cout << "Row not found\n";

    return -1;
}

std::string CSVWriter::getRow(int &lineNumber)
{
    std::fstream file;
    file.open(filename, std::ios::in);

    int currentLine = 0;
    std::vector<std::string> row;
    std::string line, word, temp;

    while (file >> temp)
    {
        getline(file, line);
        currentLine ++;
        if (currentLine == lineNumber) {
            file.close();
            return line;
        }
    }
    file.close();
    return "";
}

std::vector<std::string> CSVWriter::getRowVector(int &lineNumber)
{
    std::fstream file;
    file.open(filename, std::ios::in);
    int currentLine = 0;
    bool found = false;

    std::vector<std::string> row;
    std::string line, word, temp;

    while (file >> temp)
    {
        row.clear();
        getline(file, line);
        currentLine++;

        if (currentLine == lineNumber)
        {
            std::stringstream s(line);
            while (getline(s, word, delimeter))
            {
                row.push_back(word);
            }
            return row;
        }
    }
}