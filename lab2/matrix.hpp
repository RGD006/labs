#pragma once
#include <vector>
#include <random>
#include <ranges>

class MatrixOperation
{
private:
    std::vector<std::vector<float>> matrix; // std::vector<> це динамічний масив

public:
    MatrixOperation(std::vector<std::vector<float>> _matrix);
    float sum();
    void printMatrix() const;
};

MatrixOperation::MatrixOperation(std::vector<std::vector<float>> _matrix)
    : matrix(_matrix)
{
}

float MatrixOperation::sum()
{
    float max_number = 0;
    float min_number = 0;
    for (auto row : matrix)
    {
        max_number += std::ranges::max(row); // функція пошуку максимального числа в рядку
        min_number += *std::ranges::min_element(row,
                                                [](float a, float b)
                                                {
                                                    // лямбда-функція, в котрій йде пошук мінміального числа кратному 2 
                                                    return a < b && static_cast<int>(a) % 2 == 0; 
                                                });
    }

    return max_number + min_number;
}

void MatrixOperation::printMatrix() const
{
    for (const auto row : matrix) // = foreach()
    {
        for (const auto n : row)
        {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }
}

float randomNumber() // генерує випадкові дробові числа
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-5.0, 5.0);

    return dis(gen);
}