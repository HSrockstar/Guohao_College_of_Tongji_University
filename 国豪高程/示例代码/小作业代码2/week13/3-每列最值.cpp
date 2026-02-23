//#include <iostream>
//#define ARRAY_ROWS 6
//#define ARRAY_COLS 6
//using namespace std;
//
//void find_cols_max(int(*matrix)[ARRAY_COLS], int* cols_max)
//{
//    /****************** TODO ******************/
//    for (int i = 0; i < ARRAY_COLS; i++)
//    {
//        *(cols_max + i) = matrix[0][i];
//        for (int j = 1; j < ARRAY_ROWS; j++)
//        {
//            if (*(cols_max + i) < matrix[j][i])
//            {
//                *(cols_max + i) = matrix[j][i];
//            }
//        }
//    }
//    /**************** TODO-END ****************/
//}
//void find_cols_min(int(*matrix)[ARRAY_COLS], int* cols_min)
//{
//    /****************** TODO ******************/
//    for (int i = 0; i < ARRAY_COLS; i++)
//    {
//        *(cols_min + i) = matrix[0][i];
//        for (int j = 1; j < ARRAY_ROWS; j++)
//        {
//            if (*(cols_min + i) > matrix[j][i])
//            {
//                *(cols_min + i) = matrix[j][i];
//            }
//        }
//    }
//    /**************** TODO-END ****************/
//}
//
//int main()
//{
//    int matrix[ARRAY_ROWS][ARRAY_COLS] = {};
//    int cols_max[ARRAY_COLS] = {}; // 存放每一列的最大值
//    int cols_min[ARRAY_COLS] = {}; // 存放每一列的最小值
//
//    for (int i = 0; i < ARRAY_ROWS; ++i) {
//        for (int j = 0; j < ARRAY_COLS; ++j)
//            cin >> matrix[i][j];
//    }
//
//    find_cols_max(matrix, cols_max);
//    find_cols_min(matrix, cols_min);
//
//    cout << "Cols max: ";
//    for (int i = 0; i < ARRAY_COLS; ++i) {
//        cout << cols_max[i] << ' ';
//    }
//    cout << endl;
//
//    cout << "Cols min: ";
//    for (int i = 0; i < ARRAY_COLS; ++i) {
//        cout << cols_min[i] << ' ';
//    }
//    cout << endl;
//
//    return 0;
//}