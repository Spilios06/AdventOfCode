#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

bool evaluateLine(std::string line){
    std::vector<char> level;
    for(int i = 0; i < line.size(); i++){
        int j = 0;
        while(line[i] != ' '){
            level[j] += line[i];
            i++;
        }
        j++;
    }
    return true;
}

int main(){
    int safeCount = 0;
    std::ifstream file("input.txt");
    std::string line;
    while(std::getline(file, line)){
        if(evaluateLine(line)){
            safeCount++;
        }
    }
    std::cout << safeCount << std::endl;
}