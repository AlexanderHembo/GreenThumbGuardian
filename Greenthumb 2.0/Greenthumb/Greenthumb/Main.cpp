// main.cpp
#include "FileHandler.h"
#include <chrono>
#include <thread>
#include <vector>
#include <iostream>

int main() {
    FileHandler fileHandler("C:/Users/sebbe/Desktop/New File.txt");  // Filename is "New File.txt"
    std::vector<std::string> testData = {
       "12:12, 23 #2"
    };

    int index = 0;

    while (true) {
        // Loop through the test data and restart if at the end
        if (index >= testData.size()) {
            index = 0;
        }

        //fileHandler.writeData(testData[index]);  // Write the current test data entry

        std::string lastTime = fileHandler.readLastTime();
        std::cout << "Latest entry: " << lastTime;
        std::string lastTemp = fileHandler.readLastTemp();
        std::cout << "  Latest entry of Temperature: " << lastTemp;
        std::string lastLight = fileHandler.readLastLight();
        std::cout << "  Latest entry of light hours: " << lastLight << std::endl;
        index++;

        // Wait for a second before the next write-read cycle
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}

/*
// main.cpp
#include "FileHandler.h"
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    FileHandler fileHandler("C:/Users/sebbe/Desktop/New File.txt");  // Use the correct path

    while (true) {
        std::string content = fileHandler.readAll();
        std::cout << "Latest entry: " << content << std::endl;

        // Wait for a second before the next read cycle
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}*/