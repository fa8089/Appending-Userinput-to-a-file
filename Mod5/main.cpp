#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void appendToFile(const std::string& filename) {
    std::ofstream outfile;
    outfile.open(filename, std::ios_base::app); // Open file in append mode

    if (!outfile) {
        std::cerr << "Error opening file for appending: " << filename << std::endl;
        return;
    }

    std::string userInput;
    std::cout << "Enter text to append: ";
    std::getline(std::cin, userInput);

    outfile << userInput << std::endl;
    outfile.close();
}

void reverseFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream infile(inputFilename);
    if (!infile) {
        std::cerr << "Error opening file for reading: " << inputFilename << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    std::reverse(content.begin(), content.end());

    std::ofstream outfile(outputFilename);
    if (!outfile) {
        std::cerr << "Error opening file for writing: " << outputFilename << std::endl;
        return;
    }

    outfile << content;
    outfile.close();
}

int main() {
    const std::string inputFilename = "CSC450_CT5_mod5.txt";
    const std::string outputFilename = "CSC450-mod5-reverse.txt";

    appendToFile(inputFilename);
    reverseFileContent(inputFilename, outputFilename);

    std::cout << "User input appended and file content reversed successfully." << std::endl;

    return 0;
}
