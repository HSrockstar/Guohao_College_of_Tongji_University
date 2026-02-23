#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	char color, voice, feeling;
	double rou;
	cin >> color >> voice >> feeling >> rou;
	switch (color)
	{
		case 'W': 
			cout << "这个瓜是坏瓜。";
			break;
		case 'B':
			if (rou < 0.4) cout << "这个瓜是好瓜。";
			else cout << "这个瓜是坏瓜。";
			break;
		case 'G':
			if (voice == 'M') cout << "这个瓜是好瓜。";
			else
			{
				if(feeling == 'H') cout << "这个瓜是好瓜。";
				else cout << "这个瓜是坏瓜。";
			}
	}
	return 0;
}