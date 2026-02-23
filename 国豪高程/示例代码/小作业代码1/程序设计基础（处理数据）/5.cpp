#include <iostream>
using namespace std;
int main()
{
	int du = 0, fen = 0, miao = 0;
	cin >> du >> fen >> miao;
	double weidu = du + fen / 60.0 + miao / 3600.0;
	cout << weidu;
	return 0;
}