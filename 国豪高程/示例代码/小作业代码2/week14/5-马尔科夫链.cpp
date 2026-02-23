//#include <iostream>
//#include <iomanip>
//# define STATUS_NUM 3 // 状态数
//using namespace std;
//
///****************** TODO ******************/
//double* next_status(double* status, double statusTransfer[STATUS_NUM][STATUS_NUM])  
//{  
//    double newstatus[STATUS_NUM] = { 0,0,0 };  
//    for (int i = 0; i < STATUS_NUM; i++)  
//    {  
//        for (int j = 0; j < STATUS_NUM; j++)  
//        {  
//            newstatus[i] += status[j] * statusTransfer[j][i];  
//        }  
//    }  
//    for (int i = 0; i < STATUS_NUM; i++)  
//    {  
//        status[i] = newstatus[i];  
//    }  
//    return status;  
//}
//
//
///**************** TODO-END ****************/
//
//int main()
//{
//	double status[STATUS_NUM] = {}; // 状态数组
//	// 输入
//	for (int i = 0; i < STATUS_NUM; i++)
//	{
//		cin >> status[i];
//	}
//
//	// 状态转移矩阵
//	double statusTransfer[STATUS_NUM][STATUS_NUM] = {
//		{0.1, 0.2, 0.7},
//		{0.3, 0.5, 0.2},
//		{0.7, 0.1, 0.2}
//	};
//
//	// 保留两位小数
//	cout << fixed << setprecision(2);
//
//	next_status(status, statusTransfer);
//	cout << "第一次转移后：" << endl;
//	for (int i = 0; i < STATUS_NUM; i++)
//	{
//		cout << status[i] << ' ';
//	}
//	cout << endl;
//
//	next_status(next_status(status, statusTransfer), statusTransfer);
//	cout << "第三次转移后：" << endl;
//	for (int i = 0; i < STATUS_NUM; i++)
//	{
//		cout << status[i] << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}