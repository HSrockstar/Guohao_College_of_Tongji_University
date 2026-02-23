#include <iostream>
using namespace std;

void anticlockwise_print(int* array, int rows, int cols)
{
    /****************** TODO ******************/
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int count = 0;
    int total = rows * cols;

    while (count < total)
    {
        for (int i = top; i <= bottom && count < total; ++i)
        {
            int idx = i * cols + left;
            cout << array[idx];
            count++;
            if (count < total) cout << " ";
        }
        left++;

        for (int j = left; j <= right && count < total; ++j)
        {
            int idx = bottom * cols + j;
            cout << array[idx];
            count++;
            if (count < total) cout << " ";
        }
        bottom--;

        for (int i = bottom; i >= top && count < total; --i)
        {
            int idx = i * cols + right;
            cout << array[idx];
            count++;
            if (count < total) cout << " ";
        }
        right--;

        for (int j = right; j >= left && count < total; --j)
        {
            int idx = top * cols + j;
            cout << array[idx];
            count++;
            if (count < total) cout << " ";
        }
        top++;
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