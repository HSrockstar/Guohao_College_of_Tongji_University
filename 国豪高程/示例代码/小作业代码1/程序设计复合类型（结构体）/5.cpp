#include <iostream>
#include <string>
using namespace std;

struct BookInfo
{
	string name;
	string author;
	int pages;
	int time = 0;
};

BookInfo book_list[10];

void all_time_increase(int book_amount)
{
	for (int i = 0; i < book_amount; i++)
	{
		book_list[i].time++;
	}
}

void print_list(int book_amount)
{
	for (int i = 0; i < book_amount; i++)
	{
		cout << book_list[i].name << " "
			<< book_list[i].author << " "
			<< book_list[i].pages << " " << endl;
	}
}

void find_book(string bookname, int book_amount)
{
	for (int i = 0; i < book_amount; i++)
	{
		if (book_list[i].name == bookname)
		{
			book_list[i].time = 0; // 找到书并且重置阅读时间
			break;
		}
	}
}

void remove_book(int max_time_index)
{
	for (int i = max_time_index; i < 9; i++)
	{
		book_list[i] = book_list[i + 1];
	}
}

int main()
{
	string opr; // put/read/quit
	int book_amount = 0;
	while (cin >> opr)
	{
		if (opr == "quit")
		{
			print_list(book_amount);
			break;
		}
		else if (opr == "put" && book_amount < 10)
		{
			cin >> book_list[book_amount].name >> book_list[book_amount].author >> book_list[book_amount].pages;
			all_time_increase(book_amount);
			book_list[book_amount].time = 0;
			book_amount++;
		}
		else if (opr == "put" && book_amount >= 10)
		{
			all_time_increase(book_amount);
			// 找到未阅读时间最长的书并替换
			int max_time_index = 0;
			for (int j = 0; j < book_amount; j++)
			{
				if (book_list[j].time > book_list[max_time_index].time)
				{
					max_time_index = j;
				}
			}
			remove_book(max_time_index);
			cin >> book_list[9].name >> book_list[9].author >> book_list[9].pages;
			book_list[9].time = 0;
		}
		else if (opr == "read")
		{
			string bookname;
			cin >> bookname;
			all_time_increase(book_amount);
			find_book(bookname, book_amount);
		}
	}
	return 0;
}