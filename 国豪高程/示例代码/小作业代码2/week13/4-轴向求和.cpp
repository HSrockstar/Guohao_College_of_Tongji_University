//#include <iostream>
//using namespace std;
//
//void sum(int* matrix, int axis, int* answer)
//{
//    /****************** TODO ******************/
//    if (axis == 0)
//    {
//        for (int i = 0; i < 3; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                *(answer + 3 * i + j) = *(matrix + 9 * 0 + 3 * i + j) + *(matrix + 9 * 1 + 3 * i + j) + *(matrix + 9 * 2 + 3 * i + j);
//            }
//        }
//    }
//    else if (axis == 1)
//    {
//        for (int i = 0; i < 3; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                *(answer + 3 * i + j) = *(matrix + 9 * i + 3 * 0 + j) + *(matrix + 9 * i + 3 * 1 + j) + *(matrix + 9 * i + 3 * 2 + j);
//            }
//        }
//    }
//    else if (axis == 2)
//    {
//        for (int i = 0; i < 3; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                *(answer + 3 * i + j) = *(matrix + 9 * i + 3 * j + 0) + *(matrix + 9 * i + 3 * j + 1) + *(matrix + 9 * i + 3 * j + 2);
//            }
//        }
//    }
//
//    /**************** TODO-END ****************/
//}
//
//int main()
//{
//    int arr[3][3][3] = {};
//    int answer[3][3] = {};
//
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            for (int k = 0; k < 3; ++k) {
//                cin >> arr[i][j][k];
//            }
//        }
//    }
//
//    for (int axis = 0; axis < 3; ++axis)
//    {
//        sum(arr[0][0], axis, answer[0]);
//        // 输出沿着 axis 轴向求和的结果
//        cout << "axis = " << axis << endl;
//        for (int i = 0; i < 3; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                cout << answer[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//
//    return 0;
//}