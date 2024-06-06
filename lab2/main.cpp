#include <iostream> 
#include "matrix.hpp"

// 3527

// 2 (C = A+B) 6 (float) 
// 7 (Обчислити суму найбільших елементів в стовпцях (row) матриці з непарними 
// номерами та найменших елементів в стовпцях матриці (row) з парними номерами)


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