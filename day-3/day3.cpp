#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

void print(std::string output) {
    std::cout << output << std::endl;
}

bool isPartNumber(){
    return true;
}

int searchForPart(std::string currLine, std::string prevLine = "", std::string nextLine = "") {
    size_t size = currLine.size() - 1;
    for(int i = 0; i <= size; i++) {
        
    }
}

int sumOfPartNumbers(std::vector<std::string>& fileArray){
    int sum;
    int partNumber;
    size_t size = fileArray.size() - 1;

    sum = 0;
    for(int i = 0; i <= size; i++){
        std::string currLine = fileArray[i];
        std::string nextLine = i != size ? fileArray[i+1] : "";
        std::string prevLine = i != 0 ? fileArray[i-1] : "";

        sum += searchForPart(currLine, prevLine, nextLine);       
    }
    return sum;
}

std::vector<std::string> toArray(std::istream& infile){
    std::vector<std::string> result;
    std::string inputLine;

    while(std::getline(infile,inputLine)) {
        std::stringstream ss(inputLine);
        std::string arrayLine;
        while(ss >> arrayLine) {
            result.push_back(arrayLine);
        }
        result.push_back("\n");
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
    fileArray = toArray(input);
    return 0;
}