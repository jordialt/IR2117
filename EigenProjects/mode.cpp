#include <Eigen/Dense>
#include <iostream>
#include "utils_eigen.hpp"
#include <map>


int main() {
    Eigen::VectorXd elements = ReadElementsEigen();

    std::map<double,int> counts;
    for (int i = 0; i < elements.size(); i++) {
        counts[elements(i)]++;
    }

    double mode = 0;
    int mode_count = 0;
    for (auto pair : counts) {
        double value = pair.first;
        int count = pair.second;
        if (count > mode_count) {
            mode = value;
            mode_count = count;
        }
    }

    std::cout << "Mode: " << mode << std::endl;

    return 0;
}