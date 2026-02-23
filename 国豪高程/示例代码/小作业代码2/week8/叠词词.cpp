//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int main() {
//    char input[201]; // 输入
//    char result[201]; // 结果
//    char word1[17]; // 当前单词
//    char word2[17] = { '\0' }; // 上一个单词
//    int inputlength, wordlength, resultlength = 0;
//
//    // 读取输入
//    cin.getline(input, 201);
//    inputlength = static_cast<int>(strlen(input));
//
//    int i = 0;
//    while (i < inputlength)
//    {
//        int j = 0;
//        // 提取单词
//        while (i < inputlength && input[i] != ' ' && input[i] != '\0')
//        {
//            word1[j] = input[i];
//            j++;
//            i++;
//        }
//        word1[j] = '\0'; // 单词以空字符结尾
//        wordlength = j;
//
//        // 比较当前单词和上一个单词
//        if (wordlength > 0 && strcmp(word1, word2) != 0)
//        {
//            if (resultlength > 0) 
//            {
//                result[resultlength++] = ' ';
//            }
//            //输出到结果
//            for (int k = 0; k < wordlength; k++)
//            {
//                result[resultlength++] = word1[k];
//            }
//            // 更新上一个单词
//            for (int k = 0; k < wordlength; k++) 
//            {
//                word2[k] = word1[k];
//            }
//            word2[wordlength] = '\0'; //空字符结尾
//        }
//
//        // 跳过空格和标点
//        while (i < inputlength && input[i] == ' ')
//        {
//            i++;
//        }
//    }
//
//    // 输出结果
//    result[resultlength] = '\0'; 
//    for (int i = 0; i < resultlength; i++)
//    {
//        cout << result[i];
//    }
//    cout << endl;
//
//    return 0;
//}