#include <iostream>
#include <vector>
#include "utils.hpp"
int main() {
    double m=0, s=0;
    int n=0, element;
    std::vector<int> elements;
    elements=ReadElements();
    for (int i:elements)
        s+= i;
    m= s/n;
    std::cout<< "Arithmetic mean: " << m << std::endl;
    return 0;
}