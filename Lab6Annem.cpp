/*
Author: Sriya Annem
KUID: 3099295
Date: 10/19/23
Lab: Lab06
Last modified: 10/19/2023
Purpose: Execute different operations on square matrices using functions and arrays.
*/

#include <iostream>//standard input output library
#include <fstream>//provides ability to read and write to a file
#include <vector>//helps with creating matrices

const int MATRIX_SIZE = 100; //size always 100

/** function prints a matrix of integers to the console
 * The parameter matrix is a 2D array of integers with dimensions `MATRIX_SIZE` x matrixSize The parameter `matrixSize` represents the size of the square matrix
 *  indicates the number of rows and columns in the matrix
 */
void printMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

/**
 *  function multiplies two matrices matrixA and matrixB of size matrixSize and stores the result 
 * matrixA A 2D array representing the first matrix.
 * matrixB The parameter `matrixB` is a 2D array of integers with dimensions `MATRIX_SIZE` x `MATRIX_SIZE`. It represents the second matrix in the multiplication operation.
 * parameter `matrixSize` represents the size of the square matrices `matrixA`,
 * `matrixB`, and `result`. It indicates the number of rows and columns in each matrix.
 */
void multiplyMatrices(const int matrixA[MATRIX_SIZE][MATRIX_SIZE], const int matrixB[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < matrixSize; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

/**
 * The function subtracts two matrices element-wise and stores the result in another matrix.
 *  The parameter matrixSize represents the size of the square matrices matrixA,
 * matrixB. It indicates the number of rows and columns in each matrix.
 */
void subtractMatrices(const int matrixA[MATRIX_SIZE][MATRIX_SIZE], const int matrixB[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

/**
 * The function "addMatrices" takes two matrices of size MATRIX_SIZE x MATRIX_SIZE, adds their
 * corresponding elements, and stores the result in another matrix of the same size.
 */
void addMatrices(const int matrixA[MATRIX_SIZE][MATRIX_SIZE], const int matrixB[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE], int matrixSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

/*  function is responsible for loading the matrices from a file. It takes in
two 2D arrays matrixA and matrixB, an integer reference matrixSize, and a constant reference
to string filename. */
bool loadMatricesFromFile(int matrixA[MATRIX_SIZE][MATRIX_SIZE], int matrixB[MATRIX_SIZE][MATRIX_SIZE], int& matrixSize, const std::string& filename) {
    std::ifstream inputFile("matrix_input.txt");

    if (inputFile.is_open()) {
        if (!(inputFile >> matrixSize) || matrixSize <= 0 || matrixSize > MATRIX_SIZE) {
            std::cerr << "Error: Invalid matrix size." << std::endl;
            inputFile.close();
            return false;
        }

        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                if (!(inputFile >> matrixA[i][j])) {
                    std::cerr << "Error: Invalid data in the file." << std::endl;
                    inputFile.close();
                    return false;
                }
            }
        }

        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                if (!(inputFile >> matrixB[i][j])) {
                    std::cerr << "Error: Invalid data in the file for matrix B." << std::endl;
                    inputFile.close();
                    return false;
                }
            }
        }

        inputFile.close();
        std::cout << "Matrix data loaded from " << filename << " successfully." << std::endl;
        return true;
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }
}

/**
 * This C++ program loads two matrices from a file, performs addition, multiplication, and subtraction
 * operations on them, and prints the results
 * The main function is returning an integer value of 0
 */
int main() {
    int matrixA[MATRIX_SIZE][MATRIX_SIZE], matrixB[MATRIX_SIZE][MATRIX_SIZE], resultSum[MATRIX_SIZE][MATRIX_SIZE], resultProduct[MATRIX_SIZE][MATRIX_SIZE], resultDifference[MATRIX_SIZE][MATRIX_SIZE];
    int matrixSize;

    if (loadMatricesFromFile(matrixA, matrixB, matrixSize, "matrix_input.txt")) {
        std::cout << "Matrix A:" << std::endl;
        printMatrix(matrixA, matrixSize);

        std::cout << "Matrix B:" << std::endl;
        printMatrix(matrixB, matrixSize);

        addMatrices(matrixA, matrixB, resultSum, matrixSize);

        std::cout << "Matrix Sum (Matrix A + Matrix B):" << std::endl;
        printMatrix(resultSum, matrixSize);

        multiplyMatrices(matrixA, matrixB, resultProduct, matrixSize);
        std::cout << "Matrix Product (Matrix A * Matrix B):" << std::endl;
        printMatrix(resultProduct, matrixSize);

        subtractMatrices(matrixA, matrixB, resultDifference, matrixSize);
        std::cout << "Matrix Difference (Matrix A - Matrix B):" << std::endl;
        printMatrix(resultDifference, matrixSize);
    }

    return 0;
}
