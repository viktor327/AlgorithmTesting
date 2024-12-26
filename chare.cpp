#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath> // для std::abs
#include <climits> // Додаємо цей заголовок
#include <gtest/gtest.h>

class Algorithms {
public:
    // Пошук мінімального елемента масиву позитивних чисел
    static int findMinPositive(const std::vector<int>& numbers) {
        int min = INT_MAX;
        for (int num : numbers) {
            if (num > 0 && num < min) {
                min = num;
            }
        }
        if (min == INT_MAX) {
            throw std::invalid_argument("Масив не містить позитивних чисел");
        }
        std::cout<< "Вивід інформації: " << min << std::endl;
        return min;
    }

    // Розрахунок суми елементів масиву, який може складатися лише з від'ємних чисел
    static int sumNegative(const std::vector<int>& numbers) {
        int sum = 0;
        for (int num : numbers) {
            if (num >= 0) {
                throw std::invalid_argument("Масив містить неприпустимі елементи");
            }
            sum += num;
        }
        std::cout<< "Вивід інформації: " << sum << std::endl;
        return sum;
    }

    // Розрахунок N-го елементу послідовності Фібоначчі
    static long long fibonacci(int n) {
        if (n < 0) {
            throw std::invalid_argument("n не може бути від'ємним");
        }
        if (n == 0) return 0;
        if (n == 1) return 1;

        long long a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        std::cout<< "Вивід інформації: " << b << std::endl;
        return b;
    }

    // Розрахунок сили струму на ділянці кола (I = U / R)
    static double calculateCurrent(double voltage, double resistance) {
        if (resistance <= 0) {
            throw std::invalid_argument("Опір має бути більшим за нуль");
        }
        std::cout<< "Вивід інформації: " << voltage << "/" << resistance << std::endl;
        return voltage / resistance;
    }
};

// Тести
TEST(AlgorithmsTest, FindMinPositive) {
    EXPECT_EQ(Algorithms::findMinPositive({1, 5, 10}), 1);
    EXPECT_EQ(Algorithms::findMinPositive({7, 3, 9}), 3);
    EXPECT_THROW(Algorithms::findMinPositive({-5, -10, 0}), std::invalid_argument);
}

TEST(AlgorithmsTest, SumNegative) {
    EXPECT_EQ(Algorithms::sumNegative({-1, -2, -3}), -6);
    EXPECT_EQ(Algorithms::sumNegative({-10, -20, -30}), -60);
    EXPECT_THROW(Algorithms::sumNegative({-1, -2, 3}), std::invalid_argument);
}

TEST(AlgorithmsTest, Fibonacci) {
    EXPECT_EQ(Algorithms::fibonacci(0), 0);
    EXPECT_EQ(Algorithms::fibonacci(1), 1);
    EXPECT_EQ(Algorithms::fibonacci(10), 55);
    EXPECT_THROW(Algorithms::fibonacci(-1), std::invalid_argument);
}

TEST(AlgorithmsTest, CalculateCurrent) {
    EXPECT_NEAR(Algorithms::calculateCurrent(10, 5), 2.0, 1e-9);
    EXPECT_NEAR(Algorithms::calculateCurrent(15, 3), 5.0, 1e-9);
    EXPECT_THROW(Algorithms::calculateCurrent(10, 0), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

