#include <iostream>
using namespace std;

void sum(int* matrix, int axis, int* answer)
{
    /****************** TODO ******************/
    for (int m = 0; m < 9; m++) answer[m] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int idx_3d = i * 3 * 3 + j * 3 + k;
                int val = matrix[idx_3d];

                if (axis == 0)
                {
                    int idx_2d = j * 3 + k;
                    answer[idx_2d] += val;
                }
                else if (axis == 1)
                {
                    int idx_2d = i * 3 + k;
                    answer[idx_2d] += val;
                }
                else if (axis == 2)
                {
                    int idx_2d = i * 3 + j;
                    answer[idx_2d] += val;
                }
            }
        }
    }
    /**************** TODO-END ****************/
}

int main()
{
    int arr[3][3][3] = {};
    int answer[3][3] = {};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cin >> arr[i][j][k];
            }
        }
    }

    for (int axis = 0; axis < 3; ++axis)
    {
        sum(arr[0][0], axis, answer[0]);
        // 输出沿着 axis 轴向求和的结果
        cout << "axis = " << axis << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << answer[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}