//#include <iostream>
//using namespace std;
//
//bool find_path(int x, int y);
//int matrix[9][9] = { 0 };
//int path[81][2] = { 0 };
//bool path_check[9][9];
//int path_count = 0;
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//bool found = false;
//
//int main()
//{
//    for (int i = 0; i < 9; i++)
//    {
//        for (int j = 0; j < 9; j++)
//        {
//            cin >> matrix[i][j];
//            path_check[i][j] = true;
//        }
//    }
//
//    int ori_x, ori_y;
//    cin >> ori_x >> ori_y;
//
//    //寻路
//    find_path(ori_x, ori_y);
//
//    //输出path数组中的路径
//    for (int i = 0; i < 81; i++)
//    {
//        if (path[i][0] == 0 && path[i][1] == 0)
//        {
//            break;
//        }
//        else
//        {
//            cout << path[i][0] << "," << path[i][1] << endl;
//        }
//    }
//    return 0;
//}
//
//bool find_path(int x, int y)
//{
//    if (found)
//    {
//        return true;
//    }
//
//    if (x == 0 || x == 8 || y == 0 || y == 8)
//    {
//        path[path_count][0] = x;
//        path[path_count][1] = y;
//        path_count++;
//        found = true;
//        return true;
//    }
//
//    else
//    {
//        path[path_count][0] = x;
//        path[path_count][1] = y;
//        path_count++;
//        path_check[x][y] = false;
//        for (int i = 0; i < 4; i++)
//        {
//            int xx = x + dx[i];
//            int yy = y + dy[i];
//            if (xx >= 0 && xx < 9 && yy >= 0 && yy < 9 && path_check[xx][yy] && matrix[xx][yy] == 1)
//            {
//                if (found)
//                {
//                    return true;
//                }
//                if (find_path(xx, yy))
//                return true;
//            }
//        }
//
//        path_check[x][y] = true;
//        path_count--;
//        path[path_count][0] = 0;
//        path[path_count][1] = 0;
//        return false;
//    }
//}