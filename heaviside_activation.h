#ifndef HEAVISIDE_ACTIVATION_H
#define HEAVISIDE_ACTIVATION_H

class HeavisideActivation {
public:
    // Функция Хевисайда: f(x) = { 0 if x < 0; 1 if x >= 0 }
    static double activate(double x) {
        return x >= 0 ? 1.0 : 0.0;
    }

    // Производная функции Хевисайда (почти везде 0, кроме x=0)
    static double derivative(double x) {
        return 0.0; // Для обучения не подходит, но для сравнения
    }
};

#endif // HEAVISIDE_ACTIVATION_H