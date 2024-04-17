// FileHandler.cpp
#include "FileHandler.h"
#include <iostream>
#include <sstream>

FileHandler::FileHandler(const std::string& filename) : filename(filename) {}

void FileHandler::writeData(const std::string& data) {
    outFile.open(filename, std::ios::app);
    if (outFile.is_open()) {
        outFile << data << std::endl;
        outFile.close();
    }
    else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

std::string FileHandler::readLastEntry() {
    inFile.open(filename);
    std::string line, lastLine;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lastLine = line;
        }
        inFile.close();
        return lastLine;
    }
    else {
        std::cerr << "Failed to open file for reading." << std::endl;
        return "";
    }

}
std::string FileHandler::readAll() {
    std::ostringstream content;
    inFile.open(filename);
    std::string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            content << line << "\n";
        }
        inFile.close();
    }
    else {
        std::cerr << "Failed to open file for reading." << std::endl;
    }
    return content.str();
}