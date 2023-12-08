#include <fstream>
#include <sstream>
#include <iostream>

int main() {
    // Read input file line by line
    std::string line;
    int sum = 0;
    std::ifstream infile("input.txt");
    std::string empty = "\0\0";
    int number;
    char first;
    char second;
// parse for numbers
    while (std::getline(infile, line)) {
        std::string  numStr;
        
        first = '\0';
        second = '\0';

        for (char ch : line) {
            // is the character a digit?
            if (std::isdigit(ch)) {
                // is this the first digit on the line?
                if (first == '\0') {
                    first = ch;
                    second = ch;
                }

                if (second != '\0') {
                    second = ch;
                }
            }
        }
        
        numStr.push_back(first);
        numStr.push_back(second);

        // convert the number string to int
        number = std::stoi(numStr);
        sum += number;
        // reset chars 
        first = '\0';
        second = '\0';
    }
    std::cout << sum << std::endl;
    return 0;
}


