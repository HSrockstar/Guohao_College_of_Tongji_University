#ifndef EXTENDEDMATRIX_H
#define EXTENDEDMATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

const int MAXN = 100000;

class Matrix {
public:
    int rows, cols;
    int64_t data[MAXN];

    Matrix(int r, int c);
    Matrix();

    void input();
    void output() const;

	int getIndex(int i, int j) const {
		return i * cols + j;
	}
	int64_t getValue(int i, int j) const {
		return data[getIndex(i, j)];
	}
	void setValue(int i, int j, int64_t value) {
		data[getIndex(i, j)] = value;
	}
};

Matrix matrixAdd(const Matrix &A, const Matrix &B);
Matrix matrixScalarMultiply(const Matrix &A, int scalar);
Matrix matrixTranspose(const Matrix &A);
Matrix matrixMultiply(const Matrix &A, const Matrix &B);
Matrix matrixHadamard(const Matrix &A, const Matrix &B);
Matrix matrixConvolve(const Matrix &A, const Matrix &kernel, int padding = 0, int stride = 1);

Matrix padMatrix(const Matrix &A, int padding);

#endif