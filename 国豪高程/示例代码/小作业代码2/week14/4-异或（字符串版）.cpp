//#include <iostream>
//#include <string.h>
//using namespace std;
//
///****************** TODO ******************/
//string& xor_str(string& dst,const string& src) {
//
//    size_t len1 = dst.size();
//    size_t len2 = src.size();
//    string temp_src = src;
//
//    if (len1 < len2)
//    {
//        dst = string(len2 - len1, '0') + dst;
//    }
//    else if (len1 > len2)
//    {
//        temp_src = string(len1 - len2, '0') + temp_src;
//    }
//
//    for (size_t i = 0; i < dst.size(); ++i) {
//        if (dst[i] == temp_src[i])
//        {
//            dst[i] = '0';
//        }
//        else
//        {
//            dst[i] = '1';
//        }
//    }
//
//    return dst;
//}
///**************** TODO-END ****************/
//
//int main() {
//    string dst, src;
//    cin >> dst >> src;
//
//    xor_str(dst, src); // dst = dst ⊕ src
//    cout << dst << endl;
//
//    // 链式异或操作
//    xor_str(xor_str(dst, src), src); // dst = dst ⊕ src ⊕ src
//    cout << dst << endl;
//
//    // 链式异或操作
//    xor_str(dst, src) += src; // dst = dst ⊕ src + src
//    cout << dst << endl;
//
//    cout << src << endl;
//
//    return 0;
//}