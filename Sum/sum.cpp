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
	if(num>=1){
		std::cout<<"The sum from 1 to "<<num<<" is: "<<suma(num)<<std::endl;
	
	}else{
		std::cout<<"El número debe ser mayor o igual a 1";
	}
	return 0;
}
