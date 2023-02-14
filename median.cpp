#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    double m=0;
    int n=0, element;
    std::vector<int> elements;
    std::cin>>element;
    while(!std::cin.eof()){
        elements.push_back(element);
        std::cin>>element;
    }
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