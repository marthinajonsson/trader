//
// Created by mjonsson on 8/17/19.
//

#ifndef TRADER_CSVWRITER_H
#define TRADER_CSVWRITER_H

#include <string>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <utility>

namespace IO {
    class CSVWriter {
    private:
        std::string filename;
        std::string delimeter;
        int lines;
    public:
        explicit CSVWriter (std::string &filename, std::string delm = ",") :
                filename(filename), delimeter(std::move(delm)), lines(0) {}

        template<typename T>
        void addDatainRow (T first, T last)
        {
            std::fstream file;
            file.open(filename, std::ios::out | (lines ? std::ios::app : std::ios::trunc));
            for (; first != last; )
            {
                file << *first;
                if (++first != last)
                    file << delimeter;
            }
            file << "\n";
            lines++;
            file.close();
        }

        char* getDatainRow (int &line)
        {
            std::fstream file;
            file.open(filename, std::ios::in);
            char *rdBuffer;
            char buf[100];
            rdBuffer = buf;

            for (int i = 0; i < line; i++) {
                file.getline(rdBuffer , 100 , '\n');
            }
            memset(buf, 0, 100 * (sizeof buf[0]));
            file.getline(rdBuffer, 100, '\n');
            file.close();
            return rdBuffer;
        }
    };
}

#endif //TRADER_CSVWRITER_H
