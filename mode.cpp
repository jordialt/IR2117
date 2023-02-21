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
    int n=elements.size();
    int count[n],max=0;
    for(int j=0; j<n; j++){
        count[j]=0;
        for (int i=0;i<n;i++){
            if(elements[i]==elements[j]){
                count[j]++;
            }
        if(count[j]>count[max])
            max=j;
        }
    
    }

    m=elements[max];
    std::cout<< "Mode: " << m << std::endl;
    return 0;
}