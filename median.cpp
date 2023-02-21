#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"

int main() {
    double m=0;
    int n=0, element;
    std::vector<int> elements;
    elements=ReadElements();
    std::sort(elements.begin(),elements.end());
    int mid=elements.size()/2;
    if(elements.size()%2==0){
        m=double((elements[mid]+elements[mid-1]))/2;
    }else{
        m=elements[mid];
        
    }
    std::cout<< "Median: " << m << std::endl;
    return 0;
}