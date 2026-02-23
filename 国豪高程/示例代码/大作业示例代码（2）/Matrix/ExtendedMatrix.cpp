#include "ExtendedMatrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int r, int c) : rows(r), cols(c) { }
Matrix::Matrix() : rows(0), cols(0) { }

void Matrix::input() {
    cout << "请输入 " << rows << " x " << cols << " 的矩阵元素（以空格分隔）：\n";
	int x;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> x;
			setValue(i, j, x);
        }
    }
}

void Matrix::output() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << getValue(i, j) << "\t";
        }
        cout << endl;
    }
}

Matrix padMatrix(const Matrix &A, int padding) {
    int newRows = A.rows + 2 * padding;
    int newCols = A.cols + 2 * padding;
    Matrix padded(newRows, newCols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            padded.setValue(i + padding, j + padding, A.getValue(i, j));
        }
    }
    return padded;
}

Matrix matrixAdd(const Matrix &A, const Matrix &B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        throw runtime_error("矩阵加法要求两个矩阵同型！");
    }
    Matrix C(A.rows, A.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
			C.setValue(i, j, A.getValue(i, j) + B.getValue(i, j));
        }
    }
    return C;
}

Matrix matrixScalarMultiply(const Matrix &A, int scalar) {
    Matrix C(A.rows, A.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
			C.setValue(i, j, A.getValue(i, j) * scalar);
        }
    }
    return C;
}

Matrix matrixTranspose(const Matrix &A) {
    Matrix result(A.cols, A.rows);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
			result.setValue(j, i, A.getValue(i, j));
        }
    }
    return result;
}

Matrix matrixMultiply(const Matrix &A, const Matrix &B) {
    if (A.cols != B.rows) {
        throw runtime_error("矩阵乘法要求 A 的列数等于 B 的行数！");
    }
    Matrix result(A.rows, B.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            int64_t sum = 0;
            for (int k = 0; k < A.cols; k++) {
				sum += A.getValue(i, k) * B.getValue(k, j);
            }
			result.setValue(i, j, sum);
        }
    }
    return result;
}

Matrix matrixHadamard(const Matrix &A, const Matrix &B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        throw runtime_error("Hadamard 乘积要求两个矩阵同型！");
    }
    Matrix C(A.rows, A.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
			C.setValue(i, j, A.getValue(i, j) * B.getValue(i, j));
        }
    }
    return C;
}

Matrix matrixConvolve(const Matrix &A, const Matrix &kernel, int padding, int stride) {
    Matrix padded = padMatrix(A, padding);
    int kRows = kernel.rows, kCols = kernel.cols;
    int outRows = (padded.rows - kRows) / stride + 1;
    int outCols = (padded.cols - kCols) / stride + 1;
    Matrix output(outRows, outCols);
    for (int i = 0; i < outRows; i++) {
        for (int j = 0; j < outCols; j++) {
            int64_t sum = 0;
            for (int m = 0; m < kRows; m++) {
                for (int n = 0; n < kCols; n++) {
					sum += padded.getValue(i * stride + m, j * stride + n) * kernel.getValue(m, n);
                }
            }
			output.setValue(i, j, sum);
        }
    }
    return output;
}