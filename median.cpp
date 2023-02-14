#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    double m=0, s=0;
    int n=0, element;
    std::vector<int> elements;
    std::cin>>element;
    while(!std::cin.eof()){
        elements.push_back(element);
        n++;
        std::cin>>element;
    }
    std::sort(elements.begin(),elements.end());
    m= s/n;
    std::cout<< "Median: " << m << std::endl;
    return 0;
}