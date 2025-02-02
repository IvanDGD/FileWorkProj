#include "FileWork.h"
#include <fstream>
#include <iostream>
#include <string>

FileWork::FileWork(const std::string& path) : filePath(path) {}


void FileWork::displayFile() {
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
}

void FileWork::searchLine(const std::string& searchString) {
    std::ifstream file(filePath);

    int count = 0, lineNumber = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineNumber++;
        if (line.find(searchString) != std::string::npos) {
            std::cout << "Find on line " << lineNumber << ": " << line << "\n";
            count++;
        }
    }
    std::cout << "Find all: " << count << std::endl;
}

void FileWork::replaceLine(const std::string& searchString, const std::string& newString) {
    std::ifstream file(filePath);

    std::string content, line;
    int count = 0;

    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(searchString, pos)) != std::string::npos) {
            line.replace(pos, searchString.length(), newString);
            pos += newString.length();
            count++;
        }
        content += line + "\n";
    }
    file.close();

    std::ofstream outFile(filePath);
    outFile << content;

    std::cout << "Replace " << count << std::endl;
}

void FileWork::reverseFile() {
    std::ifstream file(filePath);

    std::string content, line;
    while (std::getline(file, line)) {
        content = line + "\n" + content;
    }
    file.close();

    std::ofstream outFile(filePath);
    outFile << content;
    std::cout << "File is reverse.\n";
}