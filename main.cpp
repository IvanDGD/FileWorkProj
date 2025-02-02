#include "FileWork.h"
#include <iostream>

int main() {
    std::string filePath;
    std::cout << "Enter path to file: ";
    std::cin >> filePath;

    FileWork fileHandler(filePath);
    int choice;
    do {
        std::cout << "\nMenu: "
            << "\n1. Print file"
            << "\n2. Find line"
            << "\n3. Replace line"
            << "\n4. Reverse file"
            << "\n5. Exit"
            << "\nYour choose: ";
        std::cin >> choice;

        if (choice == 1) {
            fileHandler.displayFile();
        }
        else if (choice == 2) {
            std::string searchString;
            std::cout << "Enter string for find: ";
            std::getline(std::cin, searchString);
            fileHandler.searchLine(searchString);
        }
        else if (choice == 3) {
            std::string searchString, newString;
            std::cout << "Enter string for replace: ";
            std::getline(std::cin, searchString);
            std::cout << "Enter new string: ";
            std::getline(std::cin, newString);
            fileHandler.replaceLine(searchString, newString);
        }
        else if (choice == 4) {
            fileHandler.reverseFile();
        }
        else if (choice > 5) {
            std::cout << "Choice is over 5" << std::endl;
        }
    } while (choice != 5);

    return 0;
}
