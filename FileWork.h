#pragma once
#include <string>

class FileWork
{
private:
	std::string filePath;
public:
	FileWork(const std::string& path);
	void displayFile();
	void searchLine(const std::string& searchString);
	void replaceLine(const std::string& searchString, const std::string& newString);
	void reverseFile();
};

