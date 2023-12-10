#include <fstream>
#include <iostream>
#include <vector>
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



bool isValidGame(std::string line) {
    std::stringstream ss;
    std::vector<int> cubes;
    const int redCubes = 12;
    const int greenCubes = 13;
    const int blueCubes = 14;
    // store string in string stream
    ss << line;
    std::string temp;
    int test_num;
    
    while (!ss.eof()) {
        
        ss >> temp;
        // if the the content of the string stream is successfully converted
        // to an integer, then we've found a number
        if(std::stringstream(temp) >> test_num) {
            cubes.push_back(test_num);
        }
    }
    

    
    return true;
}

int main () {
    std::string line;
    std::ifstream infile("input.txt");
    std::vector<std::string> split_line;
    int validGames;

    validGames = 0;
    
    while(std::getline(infile,line)){
        // Drop the "Game NN:" portion of the line
        size_t pos = line.find(":") + 1;
        line = line.substr(pos);
        // std::cout << str << std::endl;
        // Break up each line (game) into invidual rounds of the game
        std::vector<std::string> tokens = splitString(line, ";");
        
        if(isValidGame(line)) {
            validGames++;
         }

        for(std::string token : tokens) {
            std::cout << token << std::endl;
        }
    }
    
    std::cout << "Number of games: " << validGames << std::endl;

    return 0;
}


