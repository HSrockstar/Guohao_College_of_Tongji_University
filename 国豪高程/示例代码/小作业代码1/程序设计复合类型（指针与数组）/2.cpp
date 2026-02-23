#include <iostream>
using namespace std;

void partial_sort(int* start, int* end)
{
    /****************** TODO ******************/
    if (start >= end) return;
    for (int* i = start; i < end - 1; i++)
    {
        for (int* j = start; j < end - 1; j++)
        {
            if (*j > *(j + 1))
            {
                int temp = *(j + 1);
                *(j + 1) = *j;
                *j = temp;
            }
        }
    }
    /**************** TODO-END ****************/
}

int main()
{
    const int array_length = 10;
    int arr[array_length] = {};

    // 输入数组
    for (int i = 0; i < array_length; ++i) {
        cin >> arr[i];
    }

    // 输入左右边界
    int left = 0, right = 0;
    cin >> left >> right;

    // 调用函数
    partial_sort(arr + left, arr + right);

    // 输出数组
    for (int i = 0; i < array_length; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}