#include <gtest/gtest.h>
#include <cmath>
#include "fractional_activation.h"
#include "heaviside_activation.h"

// Тест 1: Базовая функциональность Дробилки
TEST(FractionalActivationTest, BasicFunctionality) {
    // Тестируем основные значения
    EXPECT_NEAR(FractionalActivation::activate(0.0), 0.0, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(1.0), 0.5, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(-1.0), -0.5, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(2.0), 0.666, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(-2.0), -0.666, 0.001);
}

// Тест 2: Предельные значения Дробилки
TEST(FractionalActivationTest, EdgeCases) {
    // Большие положительные значения
    EXPECT_NEAR(FractionalActivation::activate(1000.0), 0.999, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(1000000.0), 1.0, 0.001);
    
    // Большие отрицательные значения
    EXPECT_NEAR(FractionalActivation::activate(-1000.0), -0.999, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(-1000000.0), -1.0, 0.001);
    
    // Малые значения
    EXPECT_NEAR(FractionalActivation::activate(0.001), 0.001, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(-0.001), -0.001, 0.001);
}

// Тест 3: Производная Дробилки
TEST(FractionalActivationTest, DerivativeTest) {
    // Производная в нуле должна быть 1
    EXPECT_NEAR(FractionalActivation::derivative(0.0), 1.0, 0.001);
    
    // Производная для больших значений
    EXPECT_NEAR(FractionalActivation::derivative(10.0), 0.00826, 0.001);
    EXPECT_NEAR(FractionalActivation::derivative(-10.0), 0.00826, 0.001);
    
    // Производная симметрична
    EXPECT_EQ(FractionalActivation::derivative(5.0), 
              FractionalActivation::derivative(-5.0));
}

// Тест 4: Функция Хевисайда
TEST(HeavisideActivationTest, BasicFunctionality) {
    EXPECT_EQ(HeavisideActivation::activate(-10.0), 0.0);
    EXPECT_EQ(HeavisideActivation::activate(-0.1), 0.0);
    EXPECT_EQ(HeavisideActivation::activate(0.0), 1.0);
    EXPECT_EQ(HeavisideActivation::activate(0.1), 1.0);
    EXPECT_EQ(HeavisideActivation::activate(10.0), 1.0);
}

// Тест 5: Сравнение функций активации
TEST(ActivationComparisonTest, CompareAll) {
    std::vector<double> test_values = {-2.0, -1.0, 0.0, 1.0, 2.0};
    
    for (double x : test_values) {
        double heaviside = HeavisideActivation::activate(x);
        double fractional = FractionalActivation::activate(x);
        double sigmoid = 1.0 / (1.0 + exp(-x));
        
        // Проверяем что значения в ожидаемых диапазонах
        EXPECT_GE(heaviside, 0.0);
        EXPECT_LE(heaviside, 1.0);
        
        EXPECT_GE(fractional, -1.0);
        EXPECT_LE(fractional, 1.0);
        
        EXPECT_GE(sigmoid, 0.0);
        EXPECT_LE(sigmoid, 1.0);
        
        // Дробилка должна быть плавнее Хевисайда
        if (x != 0.0) {
            EXPECT_NE(fractional, heaviside);
        }
    }
}

// Тест 6: Свойства монотонности
TEST(FractionalActivationTest, Monotonicity) {
    // Дробилка должна быть монотонно возрастающей
    EXPECT_LT(FractionalActivation::activate(-5.0), 
              FractionalActivation::activate(-4.0));
    EXPECT_LT(FractionalActivation::activate(-1.0), 
              FractionalActivation::activate(0.0));
    EXPECT_LT(FractionalActivation::activate(0.0), 
              FractionalActivation::activate(1.0));
}

// Тест 7: Граничные свойства
TEST(FractionalActivationTest, BoundaryProperties) {
    // При x -> +∞, f(x) -> 1
    EXPECT_GT(FractionalActivation::activate(1000.0), 0.99);
    
    // При x -> -∞, f(x) -> -1
    EXPECT_LT(FractionalActivation::activate(-1000.0), -0.99);
    
    // Непрерывность в нуле
    EXPECT_NEAR(FractionalActivation::activate(0.0001), 
                FractionalActivation::activate(-0.0001), 0.0002);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}