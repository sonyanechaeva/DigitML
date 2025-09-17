cpp
#ifndef FRACTIONAL_ACTIVATION_H
#define FRACTIONAL_ACTIVATION_H

#include <cmath>

class FractionalActivation {
public:
    // Функция активации "Дробилка": f(x) = x / (1 + |x|)
    static double activate(double x) {
        return x / (1.0 + std::abs(x));
    }

    // Производная функции активации
    static double derivative(double x) {
        double abs_x = std::abs(x);
        double denominator = 1.0 + abs_x;
        return 1.0 / (denominator * denominator);
    }
};

#endif // FRACTIONAL_ACTIVATION_H