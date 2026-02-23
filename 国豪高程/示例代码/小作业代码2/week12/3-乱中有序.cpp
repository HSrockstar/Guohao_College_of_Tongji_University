//#include <iostream>
//#define ARRAY_LENGTH 50
//using namespace std;
//
//void decode(char* p)
//{
//    /****************** TODO ******************/
//    int length = 0;
//    while (p[length] != '\0')
//    {
//        length++;
//    }
//
//    int left = 0;
//    int right = length - 1;
//    char result[ARRAY_LENGTH];
//    int count = 0;
//
//    for (int i = 0; i < length / 2 + length % 2; i++)
//    {
//        if (left == right)
//        {
//            result[count] = p[left];
//            count++;
//            left++;
//        }
//        else if (left != right)
//        {
//            result[count] = p[left];
//            count++;
//            left++;
//            result[count] = p[right];
//            count++;
//            right--;
//        }
//    }
//    result[count] = '\0';
//    cout << result << endl;
//
//    /**************** TODO-END ****************/
//}
//
//int main()
//{
//    char str[ARRAY_LENGTH] = {};
//    cin.getline(str, ARRAY_LENGTH);
//
//    decode(str);
//
//    return 0;
//}