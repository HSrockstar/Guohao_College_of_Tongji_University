//#include <iostream>
//using namespace std;
//
//class MyQueue
//{
//private:
//	int list[20];
//	int numcount = 0;
//public:
//	void fum_push(char* instr);
//	void fum_pop();
//	void fum_max();
//	void fum_min();
//	bool fum_search(char* instr);
//	MyQueue();
//};
//
//int main()
//{
//	MyQueue MyList;
//
//	while (true)
//	{
//		char instr[20] = { "\0" };
//		char trans_str[7] = { "\0" };
//		cin.getline(instr, 20);
//		sscanf_s(instr, "%s", trans_str, (unsigned)_countof(trans_str));
//		if (strcmp(trans_str, "push") == 0)
//		{
//			MyList.fum_push(instr);
//		}
//
//		else if (strcmp(trans_str, "pop") == 0)
//		{
//			MyList.fum_pop();
//		}
//
//		else if (strcmp(trans_str, "max") == 0)
//		{
//			MyList.fum_max();
//		}
//
//		else if (strcmp(trans_str, "min") == 0)
//		{
//			MyList.fum_min();
//		}
//
//		else if (strcmp(trans_str, "search") == 0)
//		{
//			if (MyList.fum_search(instr))
//			{
//				cout << "true" << endl;
//			}
//			else
//			{
//				cout << "false" << endl;
//			}
//		}
//
//		else if (strcmp(trans_str, "quit") == 0)
//		{
//			break;
//		}
//	}
//	return 0;
//}
//
//MyQueue::MyQueue()
//{
//	for (int i = 0; i < 20; i++)
//	{
//		list[i] = 1000000;
//	}
//}
//
//void MyQueue::fum_push(char* instr)
//{
//	char trans_str[7] = { "\0" };
//	int num;
//
//	sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str),&num);
//	list[numcount] = num;
//	numcount++;
//}
//
//void MyQueue::fum_pop()
//{
//	if (list[0] == 1000000)
//	{
//		cout << "Error" << endl;
//	}
//
//	else
//	{
//		cout << list[0] << endl;
//		for (int i = 0; i < numcount-1; i++)
//		{
//			list[i] = list[i + 1];
//		}
//		list[numcount-1] = 1000000;
//		numcount--;
//	}
//}
//
//void MyQueue::fum_max()
//{
//	int temp = list[0];
//	for (int i = 1; i < 20; i++)
//	{
//		if (list[i] == 1000000)
//		{
//			break;
//		}
//
//		else
//		{
//			if (list[i] > temp)
//			{
//				temp = list[i];
//			}
//		}
//	}
//	cout << temp << endl;
//}
//
//void MyQueue::fum_min()
//{
//	int temp = list[0];
//	for (int i = 1; i < 20; i++)
//	{
//		if (list[i] == 1000000)
//		{
//			break;
//		}
//
//		else
//		{
//			if (list[i] < temp)
//			{
//				temp = list[i];
//			}
//		}
//	}
//	cout << temp << endl;
//}
//
//bool MyQueue::fum_search(char* instr)
//{
//	char trans_str[7] = { "\0" };
//	int num;
//
//	sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &num);
//
//	for (int i = 0; i < 20; i++)
//	{
//		if (list[i] == num)
//		{
//			return true;
//		}
//	}
//	return false;
//}