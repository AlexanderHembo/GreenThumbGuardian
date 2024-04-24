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

std::string FileHandler::readLastTime() {
    inFile.open(filename);
    std::string line, lastLine;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lastLine = line;
        }
        inFile.close();

        // Search for the delimiter in the last line
        size_t delimiterPos = lastLine.find(","); // Assuming ',' is the delimiter
        if (delimiterPos != std::string::npos) {
            // Return the part of the line before the delimiter
            return lastLine.substr(0, delimiterPos);
        }
        else {
            // If no delimiter is found, return the whole line or indicate the absence
            return lastLine;  // or use return "Error: Delimiter not found.";
        }
    }
    else {
        std::cerr << "Failed to open file for reading." << std::endl;
        return "Error: Unable to open file.";
    }
}

std::string FileHandler::readLastTemp() {
    inFile.open(filename);
    std::string line, lastLine;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lastLine = line;
        }
        inFile.close();

        // Check for the start delimiter in the last line
        size_t startDelimiterPos = lastLine.find(","); // Assuming ',' is the start delimiter
        size_t endDelimiterPos = lastLine.find("#");   // Assuming '#' is the end delimiter

        if (startDelimiterPos != std::string::npos && endDelimiterPos != std::string::npos && startDelimiterPos < endDelimiterPos) {
            // Return the substring from after the start delimiter to before the end delimiter
            return lastLine.substr(startDelimiterPos + 1, endDelimiterPos - startDelimiterPos - 1);
        }
        else if (startDelimiterPos != std::string::npos) {
            // If no end delimiter is found, return everything after the start delimiter
            return lastLine.substr(startDelimiterPos + 1);
        }
        else {
            // If no start delimiter is found, return an error message
            return "Error: Start delimiter not found in the last entry.";
        }
    }
    else {
        std::cerr << "Failed to open file for reading." << std::endl;
        return "Error: Unable to open file.";
    }
}

std::string FileHandler::readLastLight() {
    inFile.open(filename);
    std::string line, lastLine;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lastLine = line;
        }
        inFile.close();

        // Check for the delimiter in the last line
        size_t delimiterPos = lastLine.find("#"); // Assuming '#' is the delimiter
        if (delimiterPos != std::string::npos) {
            // Return everything after the delimiter in the last line
            return lastLine.substr(delimiterPos + 1);
        }
        else {
            // If no delimiter is found, return an error message or the whole line
            return "Error: Delimiter not found in the last entry.";
        }
    }
    else {
        std::cerr << "Failed to open file for reading." << std::endl;
        return "Error: Unable to open file.";
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