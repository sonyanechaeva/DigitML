#include <iostream>
#include <vector>
#include <cmath>
#include "fractional_activation.h"
#include "heaviside_activation.h"

void compareAllActivations() {
    std::vector<double> test_values = {-2.0, -1.0, -0.5, 0.0, 0.5, 1.0, 2.0};
    
    std::cout << "Сравнение функций активации:\n";
    std::cout << "x\tХевисайд\tДробилка\tСигмоида\n";
    std::cout << "-----------------------------------------------\n";
    
    for (double x : test_values) {
        double heaviside = HeavisideActivation::activate(x);
        double fractional = FractionalActivation::activate(x);
        double sigmoid = 1.0 / (1.0 + exp(-x));
        
        std::cout << x << "\t" << heaviside << "\t\t" 
                  << fractional << "\t\t" << sigmoid << "\n";
    }
}

int main() {
    compareAllActivations();
    return 0;
}