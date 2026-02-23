//#include <iostream>
//using namespace std;
//
//void partial_sort(int* start, int* end)
//{
//    /****************** TODO ******************/
//    int length = static_cast<int>( end - start );
//    if (length > 1)
//    {
//        for (int j = length-1; j >= 0; --j)
//        {
//            for (int k = 0; k <= (j - 1); ++k)
//            {
//                if (*(start + k) >= *(start + k + 1))
//                {
//                    int temp = *(start + k);
//                    *(start + k) = *(start + k + 1);
//                    *(start + k + 1) = temp;
//                }
//            }
//        }
//    }
//    else if (length <= 1)
//    {}
//    /**************** TODO-END ****************/
//}
//
//int main()
//{
//    const int array_length = 10;
//    int arr[array_length] = {};
//
//    // 输入数组
//    for (int i = 0; i < array_length; ++i) {
//        cin >> arr[i];
//    }
//
//    // 输入左右边界
//    int left = 0, right = 0;
//    cin >> left >> right;
//
//    // 调用函数
//    partial_sort(arr + left, arr + right);
//
//    // 输出数组
//    for (int i = 0; i < array_length; ++i) {
//        cout << arr[i] << ' ';
//    }
//    cout << endl;
//
//    return 0;
//}