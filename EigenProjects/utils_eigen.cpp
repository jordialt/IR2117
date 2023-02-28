#include <Eigen/Dense>
#include <iostream>
#include "utils_eigen.hpp"
#include <vector>

Eigen::VectorXd ReadElementsEigen() {
    std::vector<double> elements
    double x;
    
    while(std::cin>>x){
        elements.push_back(x);
    }
    int n=elements.size();
    Eigen::VectorXd vec(n);
    for (int i = 0; i < n; i++) {
    
        vec(i) = elements[i];
    }
    return vec;
}
