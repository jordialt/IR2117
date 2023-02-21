#include <iostream>
#include <vector>
#include "utils.hpp"
#include <map>

int main() {
    double m=0;
    int element;
    std::vector<int> elements;
    std::cin>> elements;
    std::map<int,int> counts;
    for (int value : elements){
        counts[value]++;
    }
    int m = 0;
    int m_count = 0;
    for (auto pair:counts){
        int value = pair.first;
        int count = pair.second;
        if (count > m_count){
            m = value;
            m_count = count;
        }
    }
    std::cout<< "Mode: " << m << std::endl;
    return 0;
}