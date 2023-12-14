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

int searchForPart(std::string& currLine, std::string prevLine, std::string& nextLine) {
    size_t size = currLine.size() - 1;
    print("Current: " + currLine);
    print("Previous: " + prevLine);
    print("Next : " + nextLine);
    for(size_t i = 0; i <= size; i++) {
        //std::cout << currLine[i];
    }
    return 0;
}

int sumOfPartNumbers(std::vector<std::string> fileArray){
    int sum;
    int partNumber;
    std::string currLine;
   // std::string nextLine;
   // std::string prevLine;
    //size_t size = fileArray.size() - 1;
    size_t size = 5;
    sum = 0;
    auto it = fileArray.begin();
    for(int i = 0; i < size; i++) {
        currLine = fileArray[i];
        auto next = std::next(it, 1);
        auto prev = std::prev(it,-1);
        print("here");
        sum += searchForPart(currLine, *prev, *next);       
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
    int sum;
    if (argc > 1) {
        file.open(argv[1]);
        if (file.is_open()) {
            // now point to the file stream
            print("file is open");
            input_ptr = &file;
            std::istream& input = *input_ptr;
            fileArray = toArray(input);
        }
    }
    // reference to the stream
    sum = sumOfPartNumbers(fileArray); 
    return 0;
}
