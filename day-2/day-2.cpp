#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <sstream>


std::vector<std::string> splitString(std::string str, std::string delim) {
    std::string token;
    std::vector<std::string> result;
    size_t end_pos;
    size_t delim_length = delim.length();
    size_t start_pos = 0;
    

    while ((end_pos = str.find(delim, start_pos)) != std::string::npos) {
        token = str.substr(start_pos, end_pos - start_pos);
        start_pos = end_pos + delim_length;

        result.push_back(token);
    }
    
    result.push_back(str.substr(start_pos));
    return result;

}

int extractInt(std::string str){
    std::stringstream ss;
    ss << str;
    std::string temp;
    int result;
    int testNumber;

    while (!ss.eof()) {
        ss >> temp;
            // if the conversion from a string to a number is successful,
            //  then we've found an integer in the string
        if (std::stringstream(temp) >> testNumber) {
            result = testNumber; 
        }
    }
    return result;
}

bool isValidGame(std::vector<std::string> tokens) {
    int cubes;
    std::string red = "\\d{1,2} red";
    std::string green = "\\d{1,2} green";
    std::string blue =  "\\d{1,2} blue";

    std::regex red_regex(red);
    std::regex green_regex(green);
    std::regex blue_regex(blue);
    std::smatch match;

    const int redCubes = 12;
    const int greenCubes = 13;
    const int blueCubes = 14;
    
    for(std::string token : tokens) {
        
        if(std::regex_search(token, match, red_regex)){
            cubes = extractInt(match[0]);
            if(cubes > redCubes){
                return false;
            }
        }

        if(std::regex_search(token, match, green_regex)){
            cubes = extractInt(match[0]);
            if(cubes > greenCubes) {
                return false;
            }
        }

        if(std::regex_search(token, match, blue_regex)) {
            cubes = extractInt(match[0]);
            if(cubes > blueCubes) {
                return false;
            }
        }
    }
    return true;
}


int main () {
    std::string line;
    std::ifstream infile("input.txt");
    std::vector<std::string> split_line;
    int sumOfGames;

    sumOfGames = 0;
    int gameId = 1;

    while(std::getline(infile,line)){
        // Drop the "Game NN:" portion of the line
        size_t pos = line.find(":") + 1;
        line = line.substr(pos);
        // Break up each line (game) into invidual rounds of the game
        std::vector<std::string> tokens = splitString(line, ";");
        
        if(isValidGame(tokens)) {
            sumOfGames += gameId;
        }
        gameId++;
    }
    
    std::cout << "Number of games: " << sumOfGames << std::endl;

    return 0;
}


