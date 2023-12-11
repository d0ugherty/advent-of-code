#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <sstream>


std::vector<std::string> splitString(const std::string& str, const std::string& delim) {
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

std::vector<int> getCubes(const std::string& token) {
    std::vector<int> cubes(3,0); // 0 - Red 1 - Green 2 - Blue
    static std::string red = "\\d{1,2} red";
    static std::string green = "\\d{1,2} green";
    static std::string blue =  "\\d{1,2} blue";

    static std::regex red_regex(red);
    static std::regex green_regex(green);
    static std::regex blue_regex(blue);
    std::smatch match;

    
    if(std::regex_search(token, match, red_regex)){
        cubes[0] = extractInt(match[0]);
    }

    if(std::regex_search(token, match, green_regex)){
        cubes[1] = extractInt(match[0]);
    }

    if(std::regex_search(token, match, blue_regex)) {
        cubes[2] = extractInt(match[0]);
    }
    return cubes;
}

bool isValidGame(std::vector<std::string>& tokens) { 
    std::vector<int> cubes;
    static const int redCubes = 12;
    static const int greenCubes = 13;
    static const int blueCubes = 14;
    

    for (std::string token : tokens) {
        cubes = getCubes(token);
        if (cubes[0] > redCubes) {
            return false;
        }

        if (cubes[1] > greenCubes) {
            return false;
        }

        if (cubes[2] > blueCubes) {
            return false;
        }  
    }
    return true;
}

int powerOfSet(std::vector<std::string>& tokens) {
    std::vector<int> cubes;
    
    int redMin = 0;
    int blueMin = 0;
    int greenMin = 0;

    for (std::string token : tokens) {
        cubes = getCubes(token);
            
        if (cubes[0] > redMin) {
            redMin = cubes[0];
        }

        if (cubes[1] > greenMin) {
            greenMin = cubes[1];
        }

        if (cubes[2] > blueMin) {
            blueMin = cubes[2];
        }
    }
    return redMin * greenMin * blueMin;
}


int main () {
    std::string line;
    std::ifstream infile("input.txt");
    std::vector<std::string> split_line;
    int sumOfGames;
    int sumOfPowers;

    sumOfGames = 0;
    sumOfPowers = 0;
    int gameId = 1;

    while(std::getline(infile,line)){
        // Drop the "Game NN:" portion of the line
        size_t pos = line.find(":") + 1;
        line = line.substr(pos);
        // Break up each line (game) into invidual rounds of the game
        std::vector<std::string> tokens = splitString(line, ";");
        
        sumOfPowers += powerOfSet(tokens);

        if(isValidGame(tokens)) {
            sumOfGames += gameId;
        }
        gameId++;
    }
    
    std::cout << "Number of games: " << sumOfGames << std::endl;
    std::cout << "Sum of powers: " << sumOfPowers << std::endl;
    return 0;
}


