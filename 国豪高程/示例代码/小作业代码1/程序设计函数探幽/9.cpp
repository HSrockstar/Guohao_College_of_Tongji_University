#include <iostream>
#include <string>
using namespace std;
char ch[3] = { 'A', 'B', 'C' };
int num = 1;
void step(char start, char end, char other, int lay)
{
	if (lay == 1)
	{
		cout << num << ". " << start << " -> " << end << endl;
		num++;
		return;
	}
	step(start, other, end, lay - 1);
	cout << num << ". " << start << " -> " << end << endl;
	num++;
	step(other, end, start, lay - 1);
}
int main()
{
	char start, end, other;
	int lay;
	cin >> start >> end >> lay;
	for (int i = 0; i < 3; i++)
	{
		if (ch[i] != start && ch[i] != end) other = ch[i];
	}
	step(start, end, other, lay);
	return 0;
}