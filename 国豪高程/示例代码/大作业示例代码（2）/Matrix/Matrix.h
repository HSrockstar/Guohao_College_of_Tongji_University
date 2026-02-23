#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
public:
    int rows, cols;
    vector<vector<int64_t>> data;

    Matrix(int r, int c);
    Matrix();

    void input();
    void output() const;
};

Matrix matrixAdd(const Matrix &A, const Matrix &B);
Matrix matrixScalarMultiply(const Matrix &A, int64_t scalar);
Matrix matrixTranspose(const Matrix &A);
Matrix matrixMultiply(const Matrix &A, const Matrix &B);
Matrix matrixHadamard(const Matrix &A, const Matrix &B);
Matrix matrixConvolve(const Matrix &A, const Matrix &kernel, int padding = 0, int stride = 1);

Matrix padMatrix(const Matrix &A, int padding);

#endif