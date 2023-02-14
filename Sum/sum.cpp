#include <iostream>

int suma( int num) {
	int suma= (num * (num+1))/2;
	return suma; 
}

int main(){
	int num;
	std::cout<<"Introduce un número: ";
	std::cin>>num;
	std::cout<<std::endl;
	while(num<1){
		std::cout<<"Vuelve a introducir un número: ";
		std::cin>>num;
		
	}
	std::cout<<"La suma de 1 a "<<num<<" es: "<<suma(num)<<std::endl;
	return 0;
}
