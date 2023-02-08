#include <iostream>
#include <cmath>
#include <complex>

int main(){
    double a,b,c;
    std::complex<double> x1,x2; 
    
    std::cout<<"Enter a: ";
    std::cin>>a;
    std::cout<<"Enter b: ";
    std::cin>>b;
    std::cout<<"Enter c: ";
    std::cin>>c;
    double discriminant= b*b-4*a*c;
    if (discriminant<0){
        std::complex<double> sqrt_discriminant(0, sqrt(-discriminant));
        x1=(-b+sqrt_discriminant)/(2*a);
        x2=(-b-sqrt_discriminant)/(2*a);
        std::cout<<"x1= "<<x1<<std::endl;
        std::cout<<"x2= "<<x2<<std::endl;
    }
    else{
        if(discriminant==0){
            x1=-b/(2*a);
            std::cout<<"x1= "<<x1<<std::endl;


        }
        else{
        x1=(-b+sqrt(discriminant))/2*a;
        x2=(-b-sqrt(discriminant))/2*a;
        std::cout<<"x1= "<<x1<<std::endl;
        std::cout<<"x2= "<<x2<<std::endl;
        }

    }
    return 0;
}