#include <iostream>
int main() {
    double m=0, s=0;
    int n=0, num=-1;
    while(num!=0){
        std::cin>>num;
        if(num!=0){
            s+=num;
            n++;
        }
    }

    m= s/n;
    std::cout<< "Arithmetic mean: " << m << std::endl;
    return 0;
}