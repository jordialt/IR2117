#include <Eigen/Dense>
#include <iostream>
#include "utils_eigen.hpp"
#include <algorithm>

int main(){
    Eigen::VectorXd elements = ReadElementsEigen();
    std::sort(elements.data(),elements.data()+elements.size());
    int mid = elements.size()/2;
    double median;
    if (elements.size() % 2 == 0) {
        median = (elements[mid] + elements[mid-1]) / 2;
    } else {
        median = elements[mid];
    }
    std::cout << "Median: " << median << std::endl;
    return 0;
}
