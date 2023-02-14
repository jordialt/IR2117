#include <iostream>
int main() {
    double m=0, s=0;
    int n=0, num;
    std::cin>>num;
    while(!std::cin.eof()){
        s+=num;
        n++;
        std::cin>>num;
    }
    

    m= s/n;
    std::cout<< "Arithmetic mean: " << m << std::endl;
    return 0;
}