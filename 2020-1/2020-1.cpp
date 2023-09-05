#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> expenses;
    std::ifstream input("input.txt");

    int number;
    while(input.peek() != EOF && input >> number) {
        expenses.push_back(number);
    }

    for(int i = 0; i + 2 < expenses.size(); i++) {
        
        int exp_1 = expenses[i];

        for(int j = i+1; j < expenses.size(); j++) {
            
            int exp_2 = expenses[j];
          
            for(int k = j + 1; k < expenses.size(); k++) {

                int exp_3 = expenses[k];
                int sum = exp_1 + exp_2+ exp_3;
                    
                if(sum == 2020) {
                    std::cout << exp_1 << " + " << exp_2 << " + " << exp_3 << " = " << "2020\n";
                    std::cout << exp_1 << " * " << exp_2 << " * " << exp_3 << " = " << exp_1 * exp_2 * exp_3 << std::endl;
                    input.close();
                    return exp_1 * exp_2 * exp_3;
                }
            }
        }
    }
    std::cout << "Try again" << std::endl;
    return 0;
}
