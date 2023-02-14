#include <iostream>
#include <vector>
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
    
    for (int i:elements)
        s+= i;
    m= s/n;
    std::cout<< "Arithmetic mean: " << m << std::endl;
    return 0;
}