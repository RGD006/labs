#include <iostream> 
#include <vector>
#include <random>
#include <ranges>

// 3527

// 2 (C = A+B) 6 (float) 
// 7 (Обчислити суму найбільших елементів в стовпцях (row) матриці з непарними 
// номерами та найменших елементів в стовпцях матриці (row) з парними номерами)

class MatrixOperation
{
private:
    std::vector<std::vector<float>> matrix;
public:
    MatrixOperation(std::vector<std::vector<float>> _matrix);
    float sum();
    void printMatrix();
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
        max_number += std::ranges::max(row);
        min_number += *std::ranges::min_element(row, 
        [](float a, float b)
        { 
            return a < b && static_cast<int>(a) % 2 == 0;
        }
        );
    }

    return max_number + min_number;
}

void MatrixOperation::printMatrix()
{
    for (const auto row : matrix)
    {
        for (const auto n : row)
        {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }
}

float randomNumber()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-5.0, 5.0); 

    return dis(gen);
}

int main()
{
    int c5 = 3527 % 5, c7 = 3527 % 7, c11 = 3527 % 11;

    std::cout << c5 << " " << c7 << " " << c11 << "\n";

    std::vector<std::vector<float>> matrix(5);

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            matrix[i].push_back(randomNumber());
        }
    }

    MatrixOperation Matrix(matrix);

    Matrix.printMatrix();

    std::cout << Matrix.sum() << std::endl;

    return EXIT_SUCCESS;
}