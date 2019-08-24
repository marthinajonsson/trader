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
#include <sstream>
#include <vector>


namespace IO {
    class CSVWriter {
    private:
        const char* filename;
        char delimeter;
        int lines;
    public:
        explicit CSVWriter (const char* filename, char delm = ',') :
                filename(filename), delimeter(delm), lines(0) {}

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

        std::string getRow (int &lineNumber);
        std::vector<std::string> getRowVector(int &lineNumber);
        std::vector<std::string> getAllLines();
        int deleteRow(int &lineNumber);
    };
}

#endif //TRADER_CSVWRITER_H
