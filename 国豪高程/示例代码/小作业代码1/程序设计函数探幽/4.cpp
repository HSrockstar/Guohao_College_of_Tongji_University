#include <iostream>
#define ARRAY_LENGTH 10
using namespace std;

/****************** TODO ******************/
void reverse_array(int arr[], int right)
{
    int arr2[ARRAY_LENGTH] = { 1, 8, -3, 9, 2, 0, -1, 7, 7, 6 };
    for (int i = right - 1; i >= 0; i--)
    {
        arr[i] = arr2[right - 1 - i];
    }
}
/**************** TODO-END ****************/

// 下面是一个使用你所编写函数的样例程序
int main()
{
    int arr[ARRAY_LENGTH] = { 1, 8, -3, 9, 2, 0, -1, 7, 7, 6 };

    int right = 0;
    cin >> right;

    reverse_array(arr, right);

    // 输出逆置后结果
    cout << "前" << right << "个元素逆置后的结果为：" << endl;
    for (int i = 0; i < ARRAY_LENGTH; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}