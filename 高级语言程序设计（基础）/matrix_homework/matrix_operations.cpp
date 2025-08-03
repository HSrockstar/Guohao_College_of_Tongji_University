#include "matrix_operations.h"

//菜单功能  
void menu()
{
    extern char choice;
    cout << "************************************************************" << endl
        << "*     1 矩阵加法         2 矩阵数乘          3 矩阵转置    *" << endl
        << "*     4 矩阵乘法         5 Hadamard乘积      6 矩阵卷积    *" << endl
        << "*     7 卷积应用         8 OUST算法          0 退出系统    *" << endl
        << "************************************************************" << endl;
    choice = _getch();
}

//矩阵加法  
void matriplus()
{
    cout << "这里是矩阵加法" << endl;
    cout << "两个列数、行数都相等的矩阵才可以相加" << endl;
    cout << "请输入这两个矩阵的行数和列数（空格隔开即可）" << endl;

    int row = 0;
    int column = 0;
    input_size(row, column);

    // 动态分配内存并初始化矩阵
    int** matrix = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[column];
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    //用户输入矩阵，用循环给我们定义的矩阵赋值
    cout << "请输入第一个矩阵（元素之间空格隔开即可）" << endl;
    input_matrix(row, column, matrix);
    cout << "请输入第二个矩阵（元素之间空格隔开即可）" << endl;
    input_matrix(row, column, matrix);

    //输出运算结果
    cout << "这两个矩阵的和为：" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    // 释放动态分配的内存  
    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//矩阵数乘
void nummulti()
{
    //几乎是复用矩阵加法的代码
    cout << "这里是矩阵数乘" << endl;
    cout << "请输入这个矩阵的行数和列数（空格隔开即可）" << endl;

    int row = 0;
    int column = 0;
    input_size(row, column);

    int** matrix = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[column];
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    cout << "请输入这个矩阵（元素之间空格隔开即可）" << endl;
    input_matrix(row, column, matrix);

    cout << "请输入你想乘的整数" << endl;
    int coefficient;
    cin >> coefficient;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = matrix[i][j] * coefficient;//唯一一处变动
        }
    }

    cout << "数乘运算后的结果为：" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//矩阵转置
void matritrans()
{
    cout << "这里是矩阵转置" << endl;
    cout << "请输入这个矩阵的行数和列数（空格隔开即可）" << endl;

    int row = 0;
    int column = 0;
    input_size(row, column);

    int** matrix = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[column];
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    cout << "请输入这个矩阵（元素之间空格隔开即可）" << endl;
    input_matrix(row, column, matrix);

    cout << "这个矩阵转置后的结果为：" << endl;
    for (int i = 0; i < column; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    system("pause");

    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//矩阵乘法
void matrimulti()
{
    cout << "这里是矩阵乘法" << endl;
    cout << "只有第一个矩阵的列数等于第二个矩阵的行数的时候，两个矩阵才可以做乘法" << endl;
    int row1 = 0;
    int column1 = 0;
    int row2 = 0;
    int column2 = 0;
    //输入列数和行数并检验
    while (true)
    {
        cout << "请输入第一个矩阵的行数和列数（空格隔开即可）" << endl;
        input_size(row1, column1);
        cout << "请输入第二个矩阵的行数和列数（空格隔开即可）" << endl;
        input_size(row2, column2);
        if (column1 == row2)
        {
            break;
        }
        else
        {
            cout << "第一个矩阵的列数不等于第二个矩阵的行数，请重新输入" << endl;
            continue;
        }
    }

    //声明矩阵并初始化
    int** matrix1 = new int* [row1];
    for (int i = 0; i < row1; ++i)
    {
        matrix1[i] = new int[column1];
    }
    for (int i = 0; i < row1; ++i)
    {
        for (int j = 0; j < column1; ++j)
        {
            matrix1[i][j] = 0;
        }
    }

    int** matrix2 = new int* [row2];
    for (int i = 0; i < row2; ++i)
    {
        matrix2[i] = new int[column2];
    }
    for (int i = 0; i < row2; ++i)
    {
        for (int j = 0; j < column2; ++j)
        {
            matrix2[i][j] = 0;
        }
    }

    cout << "请输入第一个矩阵（元素之间空格隔开即可）" << endl;
    input_matrix(row1, column1, matrix1);
    cout << "请输入第二个矩阵（元素之间空格隔开即可）" << endl;
    input_matrix(row2, column2, matrix2);

    int row = row1;
    int column = column2;
    int** matrix = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[column];
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    //计算过程
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            for (int k = 0; k < row2; ++k)
            {
                matrix[i][j] = matrix[i][j] + matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "这两个矩阵的乘积为：" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//矩阵Hadamard乘积
void hadamulti()
{
    cout << "这里是Hadamard乘积" << endl;
    cout << "两个列数、行数都相等的矩阵才可以相乘" << endl;
    cout << "请输入这两个矩阵的行数和列数（空格隔开即可）" << endl;

    int row = 0;
    int column = 0;
    input_size(row, column);

    // 动态分配内存并初始化矩阵
    int** matrix = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = new int[column];
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    //用户输入矩阵，用循环给我们定义的矩阵赋值
    cout << "请输入第一个矩阵（元素之间空格隔开即可）" << endl;
    input_matrix(row, column, matrix);
    cout << "请输入第二个矩阵（元素之间空格隔开即可）" << endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            int num;
            cin >> num;
            matrix[i][j] = matrix[i][j] * num;
        }
    }

    //输出运算结果
    cout << "这两个矩阵的Hadamard乘积为：" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    // 释放动态分配的内存  
    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//矩阵卷积
void conv()
{
    cout << "这里是矩阵卷积" << endl;
    cout << "请输入原始矩阵的行数和列数（空格隔开即可）" << endl;
    int row = 0;
    int column = 0;
    input_size(row, column);

    //// 动态分配内存并初始化矩阵
    int** matrix = new int* [row + 2];
    for (int i = 0; i < row + 2; ++i)
    {
        matrix[i] = new int[column + 2];
    }
    for (int i = 0; i < row + 2; ++i)
    {
        for (int j = 0; j < column + 2; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    //输入矩阵，实现padding=1
    cout << "请输入这个矩阵（元素之间空格隔开即可）" << endl;
    for (int i = 1; i < row + 1; ++i)
    {
        for (int j = 1; j < column + 1; ++j)
        {
            int num;
            cin >> num;
            matrix[i][j] = matrix[i][j] + num;
        }
    }

    //输入kernel
    int kernel[3][3] = { 0 };
    cout << "请输入3*3的kernel（元素之间空格隔开即可）" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int num;
            cin >> num;
            kernel[i][j] = kernel[i][j] + num;
        }
    }

    //声明并初始化result矩阵
    int** result = new int* [row];
    for (int i = 0; i < row; ++i)
    {
        result[i] = new int[column];
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            result[i][j] = 0;
        }
    }

    //实现卷积运算
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    result[i][j] += matrix[i + k][j + l] * kernel[k][l];
                }
            }
        }
    }

    cout << "这个矩阵的卷积运算结果为：" << endl;
    output_matrix(row, column, result);

    system("pause");

    for (int i = 0; i < row + 2; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    for (int i = 0; i < row; ++i)
    {
        delete[] result[i];
    }
    delete[] result;
    cin.ignore(9223372036854775807, '\n');
}

//图片处理卷积应用
void demo()
{
    Mat lena = imread("demolena.jpg", IMREAD_GRAYSCALE);
    imshow("原图", lena);

    // 定义卷积核
    Mat kernels[6] =
    {
        (Mat_<float>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1), // B1
        (Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1), // B2
        (Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1), // B3
        (Mat_<float>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1), // B4
        (Mat_<float>(3, 3) << -1, -1, 0, -1, 0, 1, 0, 1, 1), // B5
        (Mat_<float>(3, 3) << 1, 2, 1, 2, 4, 2, 1, 2, 1) // B6
    };

    // 2-7. 计算卷积结果并显示
    for (int i = 0; i < 6; ++i)
    {
        Mat convolvedImage;
        float kernelSum = sum(kernels[i])[0]; // 计算卷积核的总和

        // 如果卷积核总和不为0，进行归一化
        if (kernelSum != 0)
        {
            kernels[i] /= kernelSum;
        }

        // 应用卷积
        filter2D(lena, convolvedImage, -1, kernels[i]);

        // 显示结果
        string windowName = "第" + to_string(i + 1) + "个卷积核处理后的图像";
        imshow(windowName, convolvedImage);
    }
    waitKey(0); // 等待用户按键
}

//OTSU算法实现
void OUST()
{
    Mat image = imread("demolena.jpg", IMREAD_GRAYSCALE);

    // 使用Otsu算法进行阈值分割
    Mat binaryImage;
    double thresholdValue = threshold(image, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 显示结果
    imshow("原图", image);
    imshow("二值化图像", binaryImage);

    waitKey(0);
}

//输入回车继续  
void wait_for_enter()
{
    cout << "按回车键继续" << endl;
    while (_getch() != '\r')
        ;
}

//矩阵大小输入
void input_size(int& row, int& column)
{
    while (true)
    {
        cout << "请输入矩阵的行数和列数（空格隔开）: ";
        cin >> row >> column;
        if (!cin.fail())
        {
            // 检查输入是否为正整数
            if (row > 0 && column > 0)
            {
                break;
            }
            else
            {
                cout << "输入无效，请输入两个正整数！" << endl;
            }
        }
        else
        {
            cout << "输入无效，请输入两个正整数！" << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
    }
    cin.ignore(9223372036854775807, '\n');
}

//矩阵输入
void input_matrix(int row, int column, int** matrix)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            int num;
            while (true)
            {
                cin >> num;
                if (cin.fail())
                {
                    cout << "输入错误，请输入数字！" << endl;
                    cin.clear();
                    cin.ignore(9223372036854775807, '\n');
                }
                else
                {
                    break;
                }
            }
            matrix[i][j] = matrix[i][j] + num;
        }
    }
    cin.ignore(9223372036854775807, '\n');
}

//矩阵输出
void output_matrix(int row, int column, int** matrix)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}