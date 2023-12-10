#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>


std::vector<std::string> split_string(std::string str, std::string delim) {
    std::string token;
    std::vector<std::string> result;
    size_t end_pos;
    size_t delim_length = delim.length();
    size_t start_pos = 0;
    
    // Drop the "Game NN:" portion of the line
    size_t pos = str.find(":") + 1;
    str = str.substr(pos);
    std::cout << str << std::endl;

    while ((end_pos = str.find(delim, start_pos)) != std::string::npos) {
        token = str.substr(start_pos, end_pos - start_pos);
        start_pos = end_pos + delim_length;

        result.push_back(token);
    }
    
    result.push_back(str.substr(start_pos));
    return result;

}

bool isValidGame(std::string line) {
    


    return true;
}

int main () {
    std::string line;
    std::ifstream infile("input.txt");
    std::vector<std::string> split_line;
    const int redCubes = 12;
    const int greenCubes = 13;
    const int blueCubes = 14;
    int validGames;

    validGames = 0;
    
    while(std::getline(infile,line)){
        // Break up each line (game) into invidual rounds of the game
        split_line = split_string(line, ";");
        
        if(isValidGame(line)) {
            validGames++;
         }

        for(std::string token : split_line) {
            //std::cout << token << std::endl;
        }
    }
    
    std::cout << "Number of games: " << validGames << std::endl;

    return 0;
}


