#include <iostream>

using namespace std;

class MyQueue
{
private:
	double queue[20];

public:
	void initialize()
	{
		for (int i = 0; i < 20; i++)
		{
			queue[i] = 0.1;
		}
	}
	void push(double x)
	{
		int i = 0;
		while (i < 20 && queue[i] != 0.1)
		{
			i++;
		}
		queue[i] = x;
	}
	void pop()
	{
		int i = 0;
		while (i < 20 && queue[i] != 0.1)
		{
			i++;
		}
		if (i == 0)
		{
			cout << "Error" << endl;
		}
		else
		{
			cout << queue[0] << endl;
			for (int j = 0; j < i; j++)
			{
				queue[j] = queue[j + 1];
			}
			queue[i] = 0.1;
		}
	}
	double findMax()
	{
		double max = -9999999;
		for (int i = 0; i < 20; i++)
		{
			if (queue[i] != 0.1 && queue[i] > max)
			{
				max = queue[i];
			}
		}
		return max;
	}
	double findMin()
	{
		double min = 9999999;
		for (int i = 0; i < 20; i++)
		{
			if (queue[i] != 0.1 && queue[i] < min)
			{
				min = queue[i];
			}
		}
		return min;
	}
	bool search(double x)
	{
		for (int i = 0; i < 20; i++)
		{
			if (queue[i] == x)
			{
				return true;
			}
		}
		return false;
	}
};

MyQueue q;

int main()
{
	double x;
	string op;
	q.initialize();
	while (cin >> op)
	{
		if (op == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if (op == "pop")
		{
			q.pop();
		}
		else if (op == "max")
		{
			cout << q.findMax() << endl;
		}
		else if (op == "min")
		{
			cout << q.findMin() << endl;
		}
		else if (op == "search")
		{
			cin >> x;
			if (q.search(x)) cout << "true" << endl;
			else cout << "false" << endl;
		}
		else if (op == "quit")
		{
			break;
		}
	}
	return 0;
}