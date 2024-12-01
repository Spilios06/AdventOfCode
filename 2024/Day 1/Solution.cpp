#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

void calcDist(std::vector<int> leftList, std::vector<int> rightList);
void calcSimilarity(std::vector<int>& leftList, std::vector<int> &rightList);

int main(){
    std::vector<int> leftList;
    std::vector<int> rightList;
    std::string line;

    //Populate arrays from files
    std::ifstream leftFile("left.txt");
    while(std::getline(leftFile, line)){
        leftList.push_back(std::stoi(line));
    }
    leftFile.close();
    std::ifstream rightFile("right.txt");
    while (std::getline(rightFile, line)){
        rightList.push_back(std::stoi(line));
    }
    rightFile.close();

   calcDist(leftList, rightList);
   calcSimilarity(leftList, rightList);
   return 0;
}

void calcDist(std::vector<int> leftList, std::vector<int> rightList){
    int totalDistance = 0;
    //Bubble sort
    for(int k = leftList.size(); k > 0; k--){
        for(int i = 0; i < k-1; i++){
            if(leftList[i] > leftList[i+1]){
                std::swap(leftList[i], leftList[i+1]);
            }
            if(rightList[i] > rightList[i+1]){
                std::swap(rightList[i], rightList[i+1]);
            }
        }
        totalDistance += abs(rightList[k-1] - leftList[k-1]);
    }
    std::cout << "Total Distance: " << totalDistance << std::endl;
}

void calcSimilarity(std::vector<int>& leftList, std::vector<int> &rightList) {
    //Hashmap to not recalculate appearances for reoccurring numbers
    std::unordered_map<int, int> cache;
    int totalSimilarity = 0;

    for (int i : leftList) {
        if (cache.find(i) == cache.end()) {
            int appearances = 0;
            for (int j : rightList) {
                if (i == j) {
                    appearances++;
                }
            }
            cache[i] = appearances;
            totalSimilarity += appearances * i;
        } else {
            totalSimilarity += cache[i] * i;
        }
    }
    std::cout << "Total Similarity: " << totalSimilarity << std::endl;
}