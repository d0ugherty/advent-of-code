#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


int sumOfPartNumbers(std::vector<std::string>& fileArray){
    return 0;
}

void print(std::string output) {
    std::cout << output << std::endl;
}

std::vector<std::string> toArray2D(std::istream& infile){
    std::vector<std::string> result;
    std::string inputLine;

    while(std::getline(infile,inputLine)) {
        std::stringstream ss(inputLine);
        std::string arrayLine;
        while(ss >> arrayLine) {
            result.push_back(arrayLine);
            print(arrayLine);
        }

        result.push_back("\n");
        print("\n");
    }
    return result;
}

int main(int argc, char* argv[]) {
    // Pointer to std::cin
    std::istream* input_ptr = &std::cin; 
    std::ifstream file;
    std::vector<std::string> fileArray;
    if (argc > 1) {
        file.open(argv[1]);
        if (file.is_open()) {
            // now point to the file stream
            input_ptr = &file;
        }
    }
    int sumOfPartNumbers;
    // reference to the stream
    std::istream& input = *input_ptr;
    fileArray = toArray2D(input);
    return 0;
}