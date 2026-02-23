#include <iostream>
using namespace std;

/****************** TODO ******************/
template <typename T>
T find_max(T a, T b, T c)
{
    T max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    return max;
}
/**************** TODO-END ****************/

// 下面是一个使用你所编写函数的样例程序
int main()
{
    // 实际上，这里使用结构体/类更好
    double sci_1, sci_2, sci_3;
    int pop_1, pop_2, pop_3;
    char cap_1, cap_2, cap_3;

    cin >> sci_1 >> sci_2 >> sci_3;
    cin >> pop_1 >> pop_2 >> pop_3;
    cin >> cap_1 >> cap_2 >> cap_3;

    cout << "科技值最大值：" << find_max<double>(sci_1, sci_2, sci_3) << endl;
    cout << "人口数最大值：" << find_max<int>(pop_1, pop_2, pop_3) << endl;
    cout << "首字母最大值：" << find_max<char>(cap_1, cap_2, cap_3) << endl;

    return 0;
}