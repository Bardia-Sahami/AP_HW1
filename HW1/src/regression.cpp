#include "regression.h"

Data regression::read_database(std::string filepath) {
    if (filepath != "fish.txt") {
        throw std::runtime_error("Invalid syntax.");
    }
    Data vect(100);
    double input1 {};
    double input2 {};
    double input3 {};
    double input4 {};
    char c1, c2, c3;
    std::ifstream list_file;
    list_file.open(filepath);
    for (size_t i {}; i < 100; i++) {
        list_file >> input1 >> c1 >> input2 >> c2 >> input3 >> c3 >> input4;   
        vect[i] = {1, input1, input2, input3, input4};
    }

    list_file.close();
    return vect;

}

double regression::hypothesis(std::vector<double> theta, std::vector<double> x) {
    double sum {};
    if (theta.size() != x.size()) {
        throw std::logic_error("theta and x vectors should have same sizes.");
    }
    for (size_t i {}; i < theta.size(); i++) {
        sum += theta[i] * x[i];
    }
    return sum;
}

double regression::cost_function(Data& dataset, std::vector<double> theta) {
    double cost{};
    for (size_t i {}; i < 100; i++) {
        std::vector<double> x {dataset[i][0], dataset[i][1], dataset[i][2], dataset[i][3]};
        cost += 0.5 * pow((regression::hypothesis(theta, x) - dataset[i][4]), 2);
    }
    return cost;
}

std::vector<double> regression::update(Data& dataset, std::vector<double> theta, const double lr) {
    for (size_t j {}; j < theta.size(); j++) {
        double sum {};
        for (size_t i {}; i < 100; i++) {
            std::vector<double> x {dataset[i][0], dataset[i][1], dataset[i][2], dataset[i][3]};
            sum += (regression::hypothesis(theta, x) - dataset[i][4])*dataset[i][j];
        }
        theta[j] = theta[j] - lr * sum;
    }
    return theta;
}

std::vector<double> regression::linear_regression(Data& dataset, std::vector<double> init_theta, const double lr) {
    for (size_t i {}; i < 10000; i++) {
        /* double old_cost {regression::cost_function(dataset, init_theta)}; //theta before updating
        std::cout << i+1 << '\t' << "-> cost: " << old_cost; */
        init_theta = regression::update(dataset, init_theta, lr);
        /* std::cout << "\t reduced cost: " << regression::cost_function(dataset, init_theta) - old_cost << std::endl; */

        // ^ The cout works. It's commented to avoid spamming in terminal. You can uncomment to try.
    }
    return init_theta;
}