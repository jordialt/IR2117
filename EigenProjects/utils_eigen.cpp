#include <Eigen/Dense>
#include <iostream>
#include "utils_eigen.hpp"

Eigen::VectorXd ReadElementsEigen() {
    int n;
    std::cin >> n;
    Eigen::VectorXd elements(n);
    for (int i = 0; i < n; i++) {
        double x;
        std::cin >> x;
        elements(i) = x;
    }
    return elements;
}
