#include <iostream>

int suma(int num){

	int suma=(num*(num+1))/2;
	return suma;
}

int main(){
	int num;
	std::cout<<"Introduce un número: ";
	std::cin>>num;
	std::cout<<std::endl;
	std::cout<<"The sum from 1 to "<<num<<" is: "<<suma(num)<<std::endl;
	return 0;
}
