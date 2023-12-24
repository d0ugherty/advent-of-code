#include <fstream>
#include <iostream>
#include <regex>

/*
 * Parses the line for integers
 *
 * Part 1 solution
 * */
int getCalibrationValue(std::string line) {
    std::string  numStr;
    std::string empty = "\0\0";
    int calValue;
    char first;
    char second;
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
    first = '\0';
    second = '\0';
    // convert the number string to int
    calValue = std::stoi(numStr);
    return calValue;   
}




char intStringToChar(std::string intString){
    if(intString == "zero" || intString == "0") 
        return '0';
    if(intString == "one" || intString == "1") 
        return '1' ;
    if(intString == "two" || intString == "2") 
        return '2';
    if(intString == "three" || intString == "3") 
        return '3';
    if(intString == "four" || intString == "4") 
        return '4';
    if(intString == "five" || intString == "5") 
        return '5';
    if(intString == "six" || intString == "6") 
        return '6';
    if(intString == "seven" || intString == "7") 
        return '7';
    if(intString == "eight" || intString == "8") 
        return '8';
    if(intString == "nine" || intString == "9") 
        return '9';
    else {
        return '\0';
    }
}
/*
 *  Solution for part two
 * */
int getCalValueRegex(std::string line) {
    std::string  numStr;
    std::string empty = "\0\0";
    int calValue;
    char first;
    char second;
    first = '\0';
    second = '\0';
    
    std::string intPattern = "(zero|one|two|three|four|five|six|seven|eight|nine|\\d)";
    std::regex intRegex(intPattern);
    std::smatch match;
    std::string::const_iterator searchStart(line.cbegin());

    while (std::regex_search(line, match, intRegex)){
        if(first == '\0') {
            first = intStringToChar(match[0]);
            second = first;
        }

        if(second != '\0') {
            second = intStringToChar(match[0]);
        }
        line = match.suffix();
    }        

    
    numStr.push_back(first);
    numStr.push_back(second);
    first = '\0';
    second = '\0';

    std::cout << "numstr : " << numStr << "\n";
    // convert the number string to int
    calValue = std::stoi(numStr);
    std::cout << calValue << "\n";
    return calValue;   
}


int main() {
    //Read input file line by line
    std::string line;
    int sum = 0;
    int partTwoSum = 0;
    
    std::ifstream infile("input4.txt");
    // parse for numbers
    while (std::getline(infile, line)) {
        
      //  sum += getCalibrationValue(line);
        partTwoSum += getCalValueRegex(line);
        std::cout << partTwoSum << "\n";
    }
    std::cout << sum << std::endl;
    std::cout << "Part two answer: " << partTwoSum << std::endl;
    return 0;
}


