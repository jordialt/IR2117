#include <iostream>
int main(){
	int num, sum=0;
	std::cout<<"Introduce un número: ";
	std::cin>>num;
	sum=(num*(num+1))/2;
	std::cout<<std::endl;
	std::cout<<"The sum from 1 to "<<num<<" is: "<<sum<<std::endl;
	return 0;
}
