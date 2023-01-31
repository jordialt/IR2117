#include <iostream>

int main(){
	int numA, numB,suma=0;
	std::cout<<"Enter a: ";
	std::cin>>numA;
	std::cout<<std::endl;
    std::cout<<"Enter b: ";
    std::cin>>numB;
    for(int i=numA;i<=numB;i++){
        suma+=i;
    }
	std::cout<<"The sum is: "<<suma<<std::endl;
	return 0;
}