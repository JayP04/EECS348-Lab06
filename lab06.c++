//Author - Jay Patel. 

#include <iostream>
#include <fstream>
#include <iomanip>

const int N = 10;
//Reading the matirx
void readMatrix(int First_matrix[N][N], int Second_matrix[N][N], int& size, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "There was an error while opening the file. " << filename << std::endl;
        exit(EXIT_FAILURE);

    }


    file >> size;
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            if (!(file >> First_matrix[i][j])) {
                std::cerr << "The data in the file is invalid. Please check.  " << filename << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }


    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            if (!(file >> Second_matrix[i][j])) {
                std::cerr << "The data in the file is invalid. Please check. " << filename << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    file.close();
}


//for Printing. 
void printing(const int matrix[N][N], int size) {

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}


//For addition.
void addition(const int First_matrix[N][N], const int Second_matrix[N][N], int result[N][N], int size) {
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            result[i][j] = First_matrix[i][j] + Second_matrix[i][j];
        }
    }
}


//for multiplication. 
void multiplication(const int First_matrix[N][N], const int Second_matrix[N][N], int result[N][N], int size) {
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;

            for (int k = 0; k < size; ++k) {
                result[i][j] += First_matrix[i][k] * Second_matrix[k][j];
            }
        }
    }
}


//For Subtraction. 
void subtraction(const int First_matrix[N][N], const int Second_matrix[N][N], int result[N][N], int size) {
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            result[i][j] = First_matrix[i][j] - Second_matrix[i][j];
        }
    }
}


//to update the element. 
void update(int matrix[N][N], int row, int col, int value, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = value;

    } else {
        std::cerr << "Either row or colmn is invalid. Please check. " << std::endl;
    }
}


//For maximum. 
void maximum(const int matrix[N][N], int size) {
    int value_maximum = matrix[0][0];

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            if (matrix[i][j] > value_maximum) {
                value_maximum = matrix[i][j];
            }
        }
    }
    std::cout << "the maximum value of matrix is: " << value_maximum << std::endl;
}


//For transpose. 
void transpose(const int matrix[N][N], int size) {
    int transposed[N][N];

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    std::cout << "Transposed matrix is:" << std::endl;
    printing(transposed, size);
}


//Main. 
int main() {

    int size;
    int First_matrix[N][N], Second_matrix[N][N], result[N][N];
    readMatrix(First_matrix, Second_matrix, size, "matrix_input.txt");



//Printing the First matrix
    std::cout << "First Matrix:" << std::endl;

    printing(First_matrix, size);
    std::cout << std::endl;



//Printing the Second matrix
    std::cout << "Second Matrix:" << std::endl;

    printing(Second_matrix, size);
    std::cout << std::endl;



//printing the addition of both the matrix
    addition(First_matrix, Second_matrix, result, size);
    std::cout << "Addition:" << std::endl;

    printing(result, size);
    std::cout << std::endl;



//Printing the multiplication of both. 
    multiplication(First_matrix, Second_matrix, result, size);
    std::cout << "Multiplication:" << std::endl;

    printing(result, size);
    std::cout << std::endl;



//Printing the subtraction of both. 
    subtraction(First_matrix, Second_matrix, result, size);
    std::cout << "Subtraction:" << std::endl;

    printing(result, size);
    std::cout << std::endl;



//Printing the updated element. 
    update(First_matrix, 1, 1, 100, size);
    std::cout << "Matrix 1 Updated:" << std::endl;

    printing(First_matrix, size);
    std::cout << std::endl;



//Gettign the max value. 
    maximum(First_matrix, size);
    std::cout << std::endl;



//At last transpose the matrix. 
    transpose(First_matrix, size);


    return 0;

}
