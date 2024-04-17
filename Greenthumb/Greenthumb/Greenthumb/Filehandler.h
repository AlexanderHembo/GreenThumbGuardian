// FileHandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>

class FileHandler {
public:
    FileHandler(const std::string& filename);
    void writeData(const std::string& data);
    std::string readLastEntry();
    std::string readAll();

private:
    std::string filename;
    std::ofstream outFile;
    std::ifstream inFile;
};

#endif
