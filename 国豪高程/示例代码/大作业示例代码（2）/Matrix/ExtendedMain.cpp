#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "ExtendedMatrix.h"
//#include "Matrix.h"
#include "ImageProcessing.h"
#include "ExtendedImageProcessing.h"

using namespace std;

void runMatrixAddition();
void runMatrixScalarMultiplication();
void runMatrixTranspose();
void runMatrixMultiplication();
void runHadamardMultiplication();
void runMatrixConvolution();

void runMatrixAddition() {
    try {
        int r, c;
        cout << "矩阵加法：\n请输入矩阵的行数和列数：";
        cin >> r >> c;
        Matrix A(r, c), B(r, c);
        cout << "输入矩阵 A：" << endl;
        A.input();
        cout << "输入矩阵 B：" << endl;
        B.input();
        Matrix C = matrixAdd(A, B);
        cout << "矩阵 A + B 的结果为：\n";
        C.output();
    } catch (const exception &e) {
        cout << "错误：" << e.what() << endl;
    }
}

void runMatrixScalarMultiplication() {
    try {
        int r, c, scalar;
        cout << "矩阵数乘：\n请输入矩阵的行数和列数：";
        cin >> r >> c;
        Matrix A(r, c);
        cout << "输入矩阵 A：" << endl;
        A.input();
        cout << "请输入乘数：";
        cin >> scalar;
        Matrix C = matrixScalarMultiply(A, scalar);
        cout << "矩阵数乘结果为：\n";
        C.output();
    } catch (const exception &e) {
        cout << "错误：" << e.what() << endl;
    }
}

void runMatrixTranspose() {
    try {
        int r, c;
        cout << "矩阵转置：\n请输入矩阵的行数和列数：";
        cin >> r >> c;
        Matrix A(r, c);
        cout << "输入矩阵 A：" << endl;
        A.input();
        Matrix T = matrixTranspose(A);
        cout << "矩阵 A 的转置结果为：\n";
        T.output();
    } catch (const exception &e) {
        cout << "错误：" << e.what() << endl;
    }
}

void runMatrixMultiplication() {
    try {
        int r1, c1, r2, c2;
        cout << "矩阵乘法：\n请输入矩阵 A 的行数和列数：";
        cin >> r1 >> c1;
        Matrix A(r1, c1);
        cout << "输入矩阵 A：" << endl;
        A.input();
        cout << "请输入矩阵 B 的行数和列数（要求 B 的行数等于 A 的列数）：";
        cin >> r2 >> c2;
        if (c1 != r2) {
            cout << "错误：矩阵 A 的列数必须等于矩阵 B 的行数！" << endl;
            return;
        }
        Matrix B(r2, c2);
        cout << "输入矩阵 B：" << endl;
        B.input();
        Matrix C = matrixMultiply(A, B);
        cout << "矩阵 A * B 的结果为：\n";
        C.output();
    } catch (const exception &e) {
        cout << "错误：" << e.what() << endl;
    }
}

void runHadamardMultiplication() {
    try {
        int r, c;
        cout << "Hadamard 乘积：\n请输入矩阵的行数和列数：";
        cin >> r >> c;
        Matrix A(r, c), B(r, c);
        cout << "输入矩阵 A：" << endl;
        A.input();
        cout << "输入矩阵 B：" << endl;
        B.input();
        Matrix C = matrixHadamard(A, B);
        cout << "Hadamard 乘积结果为：\n";
        C.output();
    } catch (const exception &e) {
        cout << "错误：" << e.what() << endl;
    }
}

void runMatrixConvolution() {
    try {
        int r, c;
        cout << "矩阵卷积：\n请输入主矩阵 A 的行数和列数：";
        cin >> r >> c;
        Matrix A(r, c);
        cout << "输入主矩阵 A：" << endl;
        A.input();
        cout << "请输入卷积核（3 x 3）的元素：" << endl;
        Matrix kernel(3, 3);
        kernel.input();
        Matrix result = matrixConvolve(A, kernel, 1, 1);
        cout << "卷积结果矩阵为：\n";
        result.output();
    } catch (const exception &e) {
        cout << "错误：" << e.what() << endl;
    }
}

void showMenu() {
    cout << "\n========================================\n";
    cout << "矩阵与图像处理项目 - 主菜单\n";
    cout << "1. 矩阵加法\n";
    cout << "2. 矩阵数乘\n";
    cout << "3. 矩阵转置\n";
    cout << "4. 矩阵乘法\n";
    cout << "5. Hadamard 乘积\n";
    cout << "6. 矩阵卷积\n";
    cout << "7. 卷积应用 (图像处理)\n";
	cout << "8. OTSU 算法 (图像处理)\n";
	cout << "9. 目标提取 (图像处理)\n";
    cout << "0. 退出\n";
    cout << "========================================\n";
    cout << "选择菜单项<0~9>: ";
}

int main() {
    bool Flag = false;
    while (!Flag) {
        showMenu();
        char choice = _getch();
        cout << choice << endl;
        switch (choice) {
            case '1': runMatrixAddition(); break;
            case '2': runMatrixScalarMultiplication(); break;
            case '3': runMatrixTranspose(); break;
            case '4': runMatrixMultiplication(); break;
            case '5': runHadamardMultiplication(); break;
            case '6': runMatrixConvolution(); break;
            case '7': convolutionApplication(); break;
			case '8': runOtsuAlgorithm(); break;
			case '9': runTargetExtraction(); break;
            case '0': Flag = true; cout << "退出系统！" << endl; break;
            default: cout << "输入错误，请输入 0~9 之间的数字！" << endl; break;
        }
        if (!Flag) {
            cout << "按任意键返回主菜单..." << endl;
            _getch();
            system("cls");
        }
    }
    return 0;
}