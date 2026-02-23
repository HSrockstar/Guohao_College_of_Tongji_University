//#include <iostream>
//#include <iomanip>
//using namespace std;
//
///****************** TODO ******************/
//void statistic(int* arr, int ARRAY_LENGTH, int& max, int& min, float& avg, float& var);
//void statistic(int* arr, int ARRAY_LENGTH, int& max, int& min, float& avg, float& var)
//{
//    max = arr[0];
//    min = arr[0];
//    avg = static_cast<float>(arr[0]);
//    for (int i = 1; i < ARRAY_LENGTH; ++i)
//    {
//        if (arr[i] > max)
//        {
//            max = arr[i];
//        }
//
//        if (arr[i] < min)
//        {
//            min = arr[i];
//        }
//
//        avg += static_cast<float>(arr[i]);
//    }
//    avg = avg / ARRAY_LENGTH;
//
//    for (int i = 0; i < ARRAY_LENGTH; i++)
//    {
//        var += (avg - arr[i]) * (avg - arr[i]);
//    }
//    var = var / ARRAY_LENGTH;
//}
///**************** TODO-END ****************/
//
//int main()
//{
//    const int ARRAY_LENGTH = 10;
//    int arr[ARRAY_LENGTH] = {};
//    for (int i = 0; i < ARRAY_LENGTH; ++i)
//    {
//        cin >> arr[i];
//    }
//
//    // 最大值和最小值
//    int max = 0, min = 0;
//    // 平均数和方差
//    float avg = 0, var = 0;
//
//    statistic(arr, ARRAY_LENGTH, max, min, avg, var);
//
//    cout << "max: " << max << endl;
//    cout << "min: " << min << endl;
//    // 输出平均数和方差时，保留两位小数
//    cout << fixed << setprecision(2);
//    cout << "avg: " << avg << endl;
//    cout << "var: " << var << endl;
//
//    return 0;
//}