#include <iostream>
using namespace std;
int main()
{
	char word[200]{}, temp[200]{}, guess[200]{};
	cin.getline(word, 200);
	for (int i = 0; i < strlen(word); i++) {
		temp[i] = '*';
	}
	for (int i = 0; i < strlen(word); i++) cout << temp[i];
	cout << endl;
	bool all = false;
	while (cin.getline(guess, 200) && all == false)
	{
		all = true;
		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] == guess[i])
			{
				temp[i] = word[i];
			}
			else all = false;
		}
		if (all == true) break;
		cout << temp << endl;
	}
	cout << temp << endl;
	return 0;
}