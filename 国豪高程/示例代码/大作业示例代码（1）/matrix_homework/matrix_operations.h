#pragma once
#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <iostream>
#include <conio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void menu();
void matriplus();
void nummulti();
void matritrans();
void matrimulti();
void hadamulti();
void conv();
void demo();
void OUST();
void wait_for_enter();
void input_size(int& row, int& column);
void input_matrix(int row, int column, int** matrix);
void output_matrix(int row, int column, int** matrix);

#endif