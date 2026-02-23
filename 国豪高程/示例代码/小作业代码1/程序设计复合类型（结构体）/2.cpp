#include <iostream>
#include <iomanip>
using namespace std;

struct Point {
    // 思考：如果是更高维度的点，如何定义？
    int x = 0;
    int y = 0;

    double EuclideanDistance(const Point p);
};

/****************** TODO ******************/
double newton_sqrt(double a)
{
    if (a == 0) return 0.0;
    double x = a / 2.0;
    double fabs_x;
    while (true)
    {
        // 牛顿迭代核心公式：x_new = (x + a/x) / 2
        double x_new = 0.5 * (x + a / x);
        // 达到精度要求，停止迭代
        fabs_x = (x_new - x) >= 0 ? (x_new - x) : -(x_new - x);
        if (fabs_x < 1e-3) return x_new;
        // 更新迭代值
        x = x_new;
    }
}
double Point::EuclideanDistance(const Point p)
{
    return newton_sqrt((1 - p.x) * (1 - p.x) + (2 - p.y) * (2 - p.y));
}
/**************** TODO-END ****************/

int main()
{
    Point a, b;
    a.x = 1;
    a.y = 2;

    cin >> b.x >> b.y;
    cout << fixed << setprecision(2) << a.EuclideanDistance(b) << endl;

    return 0;
}