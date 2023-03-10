#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    int rows,cols;
    double suma=0;
    std::cout<<"Enter matrix size: "<<std::endl;
    std::cin>>rows;
    cols=rows;
    MatrixXd m(rows,cols);
    std::cout<<"Enter elements(row-wise): "<<std::endl;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            std::cin>>m(i,j);

std::cout<<"The matrix is: "<<std::endl;
for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            std::cout<<m(i,j);

        };
        std::cout<<std::endl;
    }

std::cout<<"The sum of rows is: "<<std::endl;
std::cout<<m.rowwise().sum()<<std::endl;
std::cout<<"The sum of columns is: "<<std::endl;
std::cout<<m.colwise().sum()<<std::endl;



    return 0;
}

