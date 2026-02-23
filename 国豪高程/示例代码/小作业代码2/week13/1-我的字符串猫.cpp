//#include <iostream>
//using namespace std;
//
//char* my_strcat(char* dest, const char* src)
//{
//    /****************** TODO ******************/
//    // 思考：<string.h>头文件中的strcat为什么返回类型为char*？
//    int length = static_cast<int>(strlen(dest));
//
//    for (int i = 0; i < static_cast<int>(strlen(src)); i++)
//    {
//        *(dest + length + i) = *(src + i);
//    }
//    *(dest + strlen(dest)) = '\0';
//
//    return dest;
//    /**************** TODO-END ****************/
//}
//
//int main()
//{
//    const int str_length = 100;
//
//    char arr1[str_length] = {};
//    char arr2[str_length] = {};
//
//    cin.getline(arr1, str_length);
//    cin.getline(arr2, str_length);
//
//    my_strcat(arr1, arr2);
//
//    cout << arr1 << endl;
//
//    return 0;
//}