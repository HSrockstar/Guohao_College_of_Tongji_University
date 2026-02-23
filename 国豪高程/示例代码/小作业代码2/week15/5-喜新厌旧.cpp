//#include<iostream>
//using namespace std;
//
//struct book_info
//{
//	char name[30];
//	char author[30];
//	int page;
//	int put_time;
//	int read_time;
//	book_info();//默认初始化
//	void print();//输出
//};
//
//int num = 0;//放入过的书籍的数量
//int solid_time = 1;//记录put和read的时间，便于排序
//book_info book [10];
//
//int main()
//{
//	while (true)
//	{
//		char instr[70] = { "\0" };//输入的字符串
//		char trans_str[5] = { "\0" };
//
//		cin.getline(instr, 70);
//		sscanf_s(instr, "%s", trans_str, (unsigned)_countof(trans_str));
//
//		//检测put类型指令并执行
//		if (strcmp(trans_str, "put") == 0)
//		{
//			char every_name[30] = { "\0" };
//			char every_author[30] = { "\0" };
//			int every_page;
//			sscanf_s(instr, "%s %s %s %d", trans_str, (unsigned)_countof(trans_str), every_name, (unsigned)_countof(every_name), every_author, (unsigned)_countof(every_author), &every_page);
//			if (num < 10)
//			{
//				strcpy_s(book[num].name, every_name);
//				strcpy_s(book[num].author, every_author);
//				book[num].page = every_page;
//				book[num].put_time = solid_time;
//				book[num].read_time = solid_time;
//				solid_time++;
//			}
//			else
//			{
//				//按照read时间进行升序排序
//				struct book_info temp;
//				for (int i = 0; i < 9; ++i)
//				{
//					for (int j = 8; j >= i; --j)
//					{
//						if (book[j].read_time > book[j + 1].read_time)
//						{
//							temp = book[j];
//							book[j] = book[j + 1];
//							book[j + 1] = temp;
//						}
//					}
//				}
//				strcpy_s(book[0].name, every_name);
//				strcpy_s(book[0].author, every_author);
//				book[0].page = every_page;
//				book[0].put_time = solid_time;
//				book[0].read_time = solid_time;
//				solid_time++;
//			}
//			num++;
//		}
//
//		//检测read类型指令并执行
//		else if (strcmp(trans_str, "read") == 0)
//		{
//			char every_name[30] = { "\0" };
//			sscanf_s(instr, "%s %s", trans_str, (unsigned)_countof(trans_str),every_name, (unsigned)_countof(every_name));
//			for (int i = 0; i < 10; i++)
//			{
//				if (strcmp(every_name, book[i].name) == 0)
//				{
//					book[i].read_time = solid_time;
//					solid_time++;
//					break;
//				}
//			}
//		}
//
//		//检测quit类型指令并执行
//		else if (strcmp(trans_str, "quit") == 0)
//		{
//			break;
//		}
//	}
//
//	//按照put时间进行升序排序
//	struct book_info temp;
//	for (int i = 0; i < 9; ++i)
//	{
//		for (int j = 8; j >= i; --j)
//		{
//			if (book[j].put_time > book[j + 1].put_time)
//			{
//				temp = book[j];
//				book[j] = book[j + 1];
//				book[j + 1] = temp;
//			}
//		}
//	}
//
//	//输出
//	for (int i = 0; i < 10; i++)
//	{
//		book[i].print();
//	}
//	return 0;
//}
//
//book_info::book_info()
//{
//	name[0] = '\0';
//	author[0] = '\0';
//	page = 0;
//	put_time = 0;
//	read_time = 0;
//}
//
//void book_info::print()
//{
//	if (put_time != 0)
//	{
//		cout << name << " " << author << " " << page << endl;
//	}
//}