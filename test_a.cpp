#include <gtest/gtest.h>
#include <cmath>
#include "fractional_activation.h"
#include "heaviside_activation.h"

// 1. Тест базовой функциональности Дробилки
TEST(FractionalActivationTest, BasicFunctionality) {
    EXPECT_NEAR(FractionalActivation::activate(0.0), 0.0, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(1.0), 0.5, 0.001);
    EXPECT_NEAR(FractionalActivation::activate(-1.0), -0.5, 0.001);
}

// 2. Тест производной Дробилки
TEST(FractionalActivationTest, DerivativeTest) {
    EXPECT_NEAR(FractionalActivation::derivative(0.0), 1.0, 0.001);
    EXPECT_NEAR(FractionalActivation::derivative(1.0), 0.25, 0.001);
}

// 3. Тест функции Хевисайда
TEST(HeavisideActivationTest, BasicFunctionality) {
    EXPECT_EQ(HeavisideActivation::activate(-10.0), 0.0);
    EXPECT_EQ(HeavisideActivation::activate(0.0), 1.0);
    EXPECT_EQ(HeavisideActivation::activate(10.0), 1.0);
}

// 4. Тест сравнения функций
TEST(ActivationComparisonTest, RangeTest) {
    // Дробилка дает значения в диапазоне [-1, 1]
    EXPECT_GE(FractionalActivation::activate(100.0), -1.0);
    EXPECT_LE(FractionalActivation::activate(100.0), 1.0);
}

// 5. Тест на симметричность производной
TEST(FractionalActivationTest, SymmetricDerivative) {
    EXPECT_EQ(FractionalActivation::derivative(5.0), 
              FractionalActivation::derivative(-5.0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}