//#include <iostream>
//using namespace std;
//
///****************** TODO ******************/
//int& find_min(int* arr, int len)
//{
//	int min_index = 0;
//	for (int i = 1; i < len; ++i)
//	{
//		if (arr[i] < arr[min_index])
//		{
//			min_index = i;
//		}
//	}
//	return arr[min_index];
//}
//
///**************** TODO-END ****************/
//
//int main()
//{
//	const int ARRAY_LENGTH = 10;
//	int arr[ARRAY_LENGTH] = {};
//	for (int i = 0; i < ARRAY_LENGTH; i++)
//	{
//		cin >> arr[i];
//	}
//
//	// 五次修改操作
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> find_min(arr, ARRAY_LENGTH); // 修改最小值
//	}
//
//	// 输出数组
//	for (int i = 0; i < ARRAY_LENGTH; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}