#include "matrix_operations.h"

//�˵�����  
void menu()
{
    extern char choice;
    cout << "************************************************************" << endl
        << "*     1 ����ӷ�         2 ��������          3 ����ת��    *" << endl
        << "*     4 ����˷�         5 Hadamard�˻�      6 ������    *" << endl
        << "*     7 ���Ӧ��         8 OUST�㷨          0 �˳�ϵͳ    *" << endl
        << "************************************************************" << endl;
    choice = _getch();
}

//����ӷ�  
void matriplus()
{
    cout << "�����Ǿ���ӷ�" << endl;
    cout << "������������������ȵľ���ſ������" << endl;
    cout << "������������������������������ո�������ɣ�" << endl;

    int row = 0;
    int column = 0;
    input_size(row, column);

    // ��̬�����ڴ沢��ʼ������
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

    //�û����������ѭ�������Ƕ���ľ���ֵ
    cout << "�������һ������Ԫ��֮��ո�������ɣ�" << endl;
    input_matrix(row, column, matrix);
    cout << "������ڶ�������Ԫ��֮��ո�������ɣ�" << endl;
    input_matrix(row, column, matrix);

    //���������
    cout << "����������ĺ�Ϊ��" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    // �ͷŶ�̬������ڴ�  
    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//��������
void nummulti()
{
    //�����Ǹ��þ���ӷ��Ĵ���
    cout << "�����Ǿ�������" << endl;
    cout << "���������������������������ո�������ɣ�" << endl;

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

    cout << "�������������Ԫ��֮��ո�������ɣ�" << endl;
    input_matrix(row, column, matrix);

    cout << "����������˵�����" << endl;
    int coefficient;
    cin >> coefficient;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = matrix[i][j] * coefficient;//Ψһһ���䶯
        }
    }

    cout << "���������Ľ��Ϊ��" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//����ת��
void matritrans()
{
    cout << "�����Ǿ���ת��" << endl;
    cout << "���������������������������ո�������ɣ�" << endl;

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

    cout << "�������������Ԫ��֮��ո�������ɣ�" << endl;
    input_matrix(row, column, matrix);

    cout << "�������ת�ú�Ľ��Ϊ��" << endl;
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

//����˷�
void matrimulti()
{
    cout << "�����Ǿ���˷�" << endl;
    cout << "ֻ�е�һ��������������ڵڶ��������������ʱ����������ſ������˷�" << endl;
    int row1 = 0;
    int column1 = 0;
    int row2 = 0;
    int column2 = 0;
    //��������������������
    while (true)
    {
        cout << "�������һ��������������������ո�������ɣ�" << endl;
        input_size(row1, column1);
        cout << "������ڶ���������������������ո�������ɣ�" << endl;
        input_size(row2, column2);
        if (column1 == row2)
        {
            break;
        }
        else
        {
            cout << "��һ����������������ڵڶ������������������������" << endl;
            continue;
        }
    }

    //�������󲢳�ʼ��
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

    cout << "�������һ������Ԫ��֮��ո�������ɣ�" << endl;
    input_matrix(row1, column1, matrix1);
    cout << "������ڶ�������Ԫ��֮��ո�������ɣ�" << endl;
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

    //�������
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

    cout << "����������ĳ˻�Ϊ��" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//����Hadamard�˻�
void hadamulti()
{
    cout << "������Hadamard�˻�" << endl;
    cout << "������������������ȵľ���ſ������" << endl;
    cout << "������������������������������ո�������ɣ�" << endl;

    int row = 0;
    int column = 0;
    input_size(row, column);

    // ��̬�����ڴ沢��ʼ������
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

    //�û����������ѭ�������Ƕ���ľ���ֵ
    cout << "�������һ������Ԫ��֮��ո�������ɣ�" << endl;
    input_matrix(row, column, matrix);
    cout << "������ڶ�������Ԫ��֮��ո�������ɣ�" << endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            int num;
            cin >> num;
            matrix[i][j] = matrix[i][j] * num;
        }
    }

    //���������
    cout << "�����������Hadamard�˻�Ϊ��" << endl;
    output_matrix(row, column, matrix);

    system("pause");

    // �ͷŶ�̬������ڴ�  
    for (int i = 0; i < row; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    cin.ignore(9223372036854775807, '\n');
}

//������
void conv()
{
    cout << "�����Ǿ�����" << endl;
    cout << "������ԭʼ������������������ո�������ɣ�" << endl;
    int row = 0;
    int column = 0;
    input_size(row, column);

    //// ��̬�����ڴ沢��ʼ������
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

    //�������ʵ��padding=1
    cout << "�������������Ԫ��֮��ո�������ɣ�" << endl;
    for (int i = 1; i < row + 1; ++i)
    {
        for (int j = 1; j < column + 1; ++j)
        {
            int num;
            cin >> num;
            matrix[i][j] = matrix[i][j] + num;
        }
    }

    //����kernel
    int kernel[3][3] = { 0 };
    cout << "������3*3��kernel��Ԫ��֮��ո�������ɣ�" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int num;
            cin >> num;
            kernel[i][j] = kernel[i][j] + num;
        }
    }

    //��������ʼ��result����
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

    //ʵ�־������
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

    cout << "�������ľ��������Ϊ��" << endl;
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

//ͼƬ������Ӧ��
void demo()
{
    Mat lena = imread("demolena.jpg", IMREAD_GRAYSCALE);
    imshow("ԭͼ", lena);

    // ��������
    Mat kernels[6] =
    {
        (Mat_<float>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1), // B1
        (Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1), // B2
        (Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1), // B3
        (Mat_<float>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1), // B4
        (Mat_<float>(3, 3) << -1, -1, 0, -1, 0, 1, 0, 1, 1), // B5
        (Mat_<float>(3, 3) << 1, 2, 1, 2, 4, 2, 1, 2, 1) // B6
    };

    // 2-7. �������������ʾ
    for (int i = 0; i < 6; ++i)
    {
        Mat convolvedImage;
        float kernelSum = sum(kernels[i])[0]; // �������˵��ܺ�

        // ���������ܺͲ�Ϊ0�����й�һ��
        if (kernelSum != 0)
        {
            kernels[i] /= kernelSum;
        }

        // Ӧ�þ��
        filter2D(lena, convolvedImage, -1, kernels[i]);

        // ��ʾ���
        string windowName = "��" + to_string(i + 1) + "������˴�����ͼ��";
        imshow(windowName, convolvedImage);
    }
    waitKey(0); // �ȴ��û�����
}

//OTSU�㷨ʵ��
void OUST()
{
    Mat image = imread("demolena.jpg", IMREAD_GRAYSCALE);

    // ʹ��Otsu�㷨������ֵ�ָ�
    Mat binaryImage;
    double thresholdValue = threshold(image, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // ��ʾ���
    imshow("ԭͼ", image);
    imshow("��ֵ��ͼ��", binaryImage);

    waitKey(0);
}

//����س�����  
void wait_for_enter()
{
    cout << "���س�������" << endl;
    while (_getch() != '\r')
        ;
}

//�����С����
void input_size(int& row, int& column)
{
    while (true)
    {
        cout << "�����������������������ո������: ";
        cin >> row >> column;
        if (!cin.fail())
        {
            // ��������Ƿ�Ϊ������
            if (row > 0 && column > 0)
            {
                break;
            }
            else
            {
                cout << "������Ч��������������������" << endl;
            }
        }
        else
        {
            cout << "������Ч��������������������" << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
    }
    cin.ignore(9223372036854775807, '\n');
}

//��������
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
                    cout << "����������������֣�" << endl;
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

//�������
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