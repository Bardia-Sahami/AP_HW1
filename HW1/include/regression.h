#ifndef REGRESSION_H
#define REGRESSION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cmath>

using Data = std::vector<std::vector<double>>;

namespace regression {
    Data read_database (std::string filepath);
    double hypothesis(std::vector<double> theta, std::vector<double> x);
    double cost_function(Data& dataset, std::vector<double> theta);
    std::vector<double> update(Data& dataset, std::vector<double> theta, const double lr);
    std::vector<double> linear_regression(Data& dataset, std::vector<double> init_theta, const double lr);

}


#endif