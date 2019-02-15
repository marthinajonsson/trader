//
// Created by mjonsson on 2/14/19.
//

#ifndef TRADER_WEBSOCKET_H
#define TRADER_WEBSOCKET_H


#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

namespace core = boost::core;
namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class WebSocket {
public:
    WebSocket() {
        init();
    }
    ~WebSocket() = default;


    int init() {
        try
        {

            auto const host = "https://ws-api.iextrading.com/1.0/deep";
            auto const port = "3000";
            auto const text = "test";

            // The io_context is required for all I/O
            net::io_context ioc;

            // These objects perform our I/O
            tcp::resolver resolver{ioc};
            websocket::stream<tcp::socket> ws{ioc};

            // Look up the domain name
            auto const results = resolver.resolve(host, port);

            // Make the connection on the IP address we get from a lookup
            net::connect(ws.next_layer(), results.begin(), results.end());

            // Perform the websocket handshake
            ws.handshake(host, "/");

            // Send the message
            ws.write(net::buffer(std::string(text)));

            // This buffer will hold the incoming message
            beast::multi_buffer buffer;

            // Read a message into our buffer
            ws.read(buffer);

            // Close the WebSocket connection
            ws.close(websocket::close_code::normal);

            // If we get here then the connection is closed gracefully

            // The make_printable() function helps print a ConstBufferSequence
//        std::cout << beast::make_printable(buffer.data()) << std::endl;
        }
        catch(std::exception const& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

private:
};


#endif //TRADER_WEBSOCKET_H
