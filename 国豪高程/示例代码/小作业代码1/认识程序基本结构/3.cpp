#include <iostream>
using namespace std;
void quote() {
	cout << "我精神状态挺好的呀！";
}
int main()
{
	for (int i = 0; i < 5; i++) {
		quote();
		if (i < 4) cout << endl;
	}
}