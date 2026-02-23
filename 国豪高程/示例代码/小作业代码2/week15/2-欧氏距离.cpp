//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//struct Point {
//    // 思考：如果是更高维度的点，如何定义？
//    int x;
//    int y;
//
//    Point(int x = 0, int y = 0) : x(x), y(y) {}
//    double EuclideanDistance(const Point& p);
//};
//
///****************** TODO ******************/
//double Point::EuclideanDistance (const Point& p)
//{
//    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
//}
///**************** TODO-END ****************/
//
//int main()
//{
//    Point a(1, 2), b;  // 思考：这样声明后，a,b的x,y的值分别是多少？
//    cin >> b.x >> b.y;
//    cout << fixed << setprecision(2) << a.EuclideanDistance(b) << endl;
//
//    return 0;
//}