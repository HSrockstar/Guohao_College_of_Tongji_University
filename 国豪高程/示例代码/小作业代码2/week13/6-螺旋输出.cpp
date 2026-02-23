#include <iostream>
using namespace std;

void anticlockwise_print(int* array, int rows, int cols)
{
    /****************** TODO ******************/
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = array[cols*i+j];
        }
    }

    int top = 0;
    int bottom = rows-1;
    int left = 0;
    int right = cols-1;

    while (true)
    {
        //向下走
        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][left] << " ";
        }
        left++;
        if (left > right)
        {
            break;
        }
        

        //向右走
        for (int i = left; i <= right; i++)
        {
            cout << matrix[bottom][i] << " ";
        }
        bottom--;
        if (top > bottom)
        {
            break;
        }

        //向上走
        for (int i = bottom; i >= top; i--)
        {
            cout << matrix[i][right] << " ";
        }
        right--;
        if (left > right)
        {
            break;
        }

        //向左走
        for (int i = right; i >= left; i--)
        {
            cout << matrix[top][i] << " ";
        }
        top++;
        if (top > bottom)
        {
            break;
        } 
    }
    /**************** TODO-END ****************/
}

int main()
{
    const int max_rows = 20, max_cols = 20;
    int rows = 0, cols = 0;
    cin >> rows >> cols;

    // 用一维数组存储矩阵
    int array[max_rows * max_cols] = {};

    // 读取矩阵
    for (int i = 0; i < rows * cols; ++i) {
        cin >> array[i];
    }

    anticlockwise_print(array, rows, cols);

    return 0;
}