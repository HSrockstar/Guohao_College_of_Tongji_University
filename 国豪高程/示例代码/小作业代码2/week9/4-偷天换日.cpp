//#include <iostream>
//#define ARRAY_LENGTH 10
//using namespace std;
//
///****************** TODO ******************/
//void reverse_array(int arr[ARRAY_LENGTH], int right);
//
//void reverse_array(int arr[ARRAY_LENGTH], int right)
//{
//    int count = right / 2;
//    for (int i = 0; i < count; i++)
//    {
//        int temp = arr[i];
//        arr[i] = arr[right - i - 1];
//        arr[right - i - 1] = temp;
//    }
//}
//
///**************** TODO-END ****************/
//
//// 下面是一个使用你所编写函数的样例程序
//int main()
//{
//    int arr[ARRAY_LENGTH] = { 1, 8, -3, 9, 2, 0, -1, 7, 7, 6 };
//
//    int right = 0;
//    cin >> right;
//
//    reverse_array(arr, right);
//
//    // 输出逆置后结果
//    cout << "前" << right << "个元素逆置后的结果为：" << endl;
//    for (int i = 0; i < ARRAY_LENGTH; ++i)
//    {
//        cout << arr[i] << ' ';
//    }
//    cout << endl;
//
//    return 0;
//}