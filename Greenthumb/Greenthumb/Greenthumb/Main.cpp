// main.cpp
#include "FileHandler.h"
#include <chrono>
#include <thread>
#include <vector>
#include <iostream>

int main() {
    FileHandler fileHandler("C:/Users/alexa/Desktop/AU/2. Semester/2. Semester Projekt/Kode/New Text Document.txt");  // Filename is "New File.txt"
    std::vector<std::string> testData = {
        "Hello, this is a test.",
        "The quick brown fox jumps over the lazy dog.",
        "Sample text data for file writing.",
        "C++ file I/O is straightforward.",
        "End of the test data set."
    };

    int index = 0;

    while (true) {
        // Loop through the test data and restart if at the end
        if (index >= testData.size()) {
            index = 0;
        }

        fileHandler.writeData(testData[index]);  // Write the current test data entry

        std::string lastEntry = fileHandler.readLastEntry();
        std::cout << "Latest entry: " << lastEntry << std::endl;

        index++;

        // Wait for a second before the next write-read cycle
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

/*
int main() {
    FileHandler fileHandler("C:/Users/sebbe/OneDrive/Skrivebord/New File.txt");  // Use the correct path

    while (true) {
        std::string content = fileHandler.readAll();
        std::cout << "Latest entry: " << content << std::endl;

        // Wait for a second before the next read cycle
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
*/