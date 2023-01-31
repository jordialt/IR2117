#include <iostream>

int main(){
	int a, b,suma=0;
	do{
		std::cout<<"Enter a: ";
		std::cin>>a;

	}while(a<1);
	std::cout<<std::endl;
	do{
		std::cout<<"Enter b: ";
    	std::cin>>b;
	}while(b<a);
    
    for(int i=a;i<=b;i++){
        suma+=i;
    }
	std::cout<<"The sum is: "<<suma<<std::endl;
	return 0;
}