#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char answer[26];
	cout << "请输入单词答案：";
	cin >> answer;
	int len = static_cast<int>(strlen(answer));
	char progress[26];
	for (int i = 0; i < len; ++i) {
		progress[i] = '*';
	}
	progress[len] = '\0';
	cout << "当前猜测进度：" << progress << endl;
	char guess[26];
	while (true) {
		cout << "请输入你的猜测：";
		cin >> guess;
		if (strcmp(guess, "end") == 0) {
			break;
		}
		for (int i = 0; i < len; ++i) {
			if (progress[i] == '*' && guess[i] == answer[i]) {
				progress[i] = answer[i];
			}
		}
		cout << "当前猜测进度：" << progress << endl;
		if (strcmp(guess, answer) == 0) {
			break;
		}
	}
	return 0;
}