#include <iostream>
using namespace std;

// 余弦相似度
double cosine_similarity(double a[], double b[], int n);
// 距离度量（欧几里得/曼哈顿/汉明）
double distance(double a[], double b[], int n, const char type[] = "Euclidean");
double distance(char a[], char b[], const char type[]);
// 杰卡德相似系数
double jaccard_similarity_coefficient(char a[], char b[]);

int main()
{
    // 1. 余弦相似度

    // 数据格式：两个三维向量
    {
        double a[3] = {};
        double b[3] = {};
        cout << "------------------------------------------" << endl;
        cout << "             Cosine Similarity            " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        cout << "Please input the second vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> b[i];
        }
        cout << "The cosine similarity is: " << cosine_similarity(a, b, 3) << endl;
    }

    // 2. 欧几里得距离

    // 数据格式：两个三维坐标
    {
        double a[3] = {};
        double b[3] = {};
        cout << "------------------------------------------" << endl;
        cout << "           Euclidean Distance             " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        cout << "Please input the second vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> b[i];
        }
        cout << "The euclidean distance is: " << distance(a, b, 3) << endl;
        // cout << "The euclidean distance is: " << distance(a, b, 3, "Euclidean") << endl;
    }

    // 3. 曼哈顿距离

    // 数据格式：两个三维坐标
    {
        double a[3] = {};
        double b[3] = {};
        cout << "------------------------------------------" << endl;
        cout << "           Manhattan Distance             " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        cout << "Please input the second vector: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> b[i];
        }
        cout << "The manhattan distance is: " << distance(a, b, 3, "Manhattan") << endl;
    }

    // 4. 汉明距离

    // 数据格式：两个字符串
    {
        char a[100] = {};
        char b[100] = {};
        cout << "------------------------------------------" << endl;
        cout << "            Hamming Distance              " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first string: " << endl;
        cin.get(); // 读取换行符（cin.getline()之前需要先读取换行符，否则会直接读取换行符，导致输入错误）
        cin.getline(a, 100);
        cout << "Please input the second string: " << endl;
        cin.getline(b, 100);
        cout << "The hamming distance is: " << distance(a, b, "Hamming") << endl;
    }

    // 5. 杰卡德相似系数

    // 数据格式：两个小写字母集合（非空），已经按照字典序排好序
    {
        char a[100] = {};
        char b[100] = {};
        cout << "------------------------------------------" << endl;
        cout << "       Jaccard Similarity Coefficient     " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Please input the first set: " << endl;
        cin >> a;
        cout << "Please input the second set: " << endl;
        cin >> b;
        cout << "The jaccard similarity coefficient is: " << jaccard_similarity_coefficient(a, b) << endl;
    }

    return 0;
}

/****************** TODO ******************/\
// 开根号（牛顿迭代法）
/*
double Nsqrt(double num)
{
    if (num == 0) return 0.0;
    double x = num / 2.0;
    double lastX;
    do
    {
        lastX = x;
        x = (x + num / x) / 2;
    }while (x - lastX > 1e-6 || lastX - x > 1e-6);
    return x;
}
*/
// 余弦相似度
double cosine_similarity(double a[], double b[], int n)
{
    double fenzi = 0, amo = 0, bmo = 0;
    for (int i = 0; i < 3; i++)
    {
        fenzi = fenzi + a[i] * b[i];
        amo += a[i] * a[i];
        bmo += b[i] * b[i];
    }
    // amo开根号
    double x = amo / 2.0;
    double lastX;
    do
    {
        lastX = x;
        x = (x + amo / x) / 2;
    } while (x - lastX > 1e-6 || lastX - x > 1e-6);
    amo = x;
    // bmo开根号
    x = bmo / 2.0;
    do
    {
        lastX = x;
        x = (x + bmo / x) / 2;
    } while (x - lastX > 1e-6 || lastX - x > 1e-6);
    bmo = x;

    double fenmu = amo * bmo;
    return (fenzi / fenmu);
}
// 距离度量（欧几里得/曼哈顿/汉明）
double distance(double a[], double b[], int n, const char type[])
{
    double result = 0;
    if (strcmp(type, "Euclidean") == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            result = result + (a[i] - b[i]) * (a[i] - b[i]);
        }
        // result开根号
        double x = result / 2.0;
        double lastX;
        do
        {
            lastX = x;
            x = (x + result / x) / 2;
        } while (x - lastX > 1e-6 || lastX - x > 1e-6);
        result = x;
    }
    if (strcmp(type, "Manhattan") == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            double temp = a[i] - b[i];
            result = result + ((temp > 0) ? temp : (0 - temp));
        }
    }
    return result;
}
double distance(char a[], char b[], const char type[])
{
    size_t len = strlen(a);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i]) count++;
    }
    return count;
}
// 杰卡德相似系数
double jaccard_similarity_coefficient(char a[], char b[])
{
    char jiaoji[26]{}; char bingji[26]{};
    int jiaoidx = 0, bingidx = 0;
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    bool isJiao;
    // 计算交集
    for (int i = 0; i < len_a; i++)
    {
        isJiao = false;
        for (int k = 0; k < jiaoidx; k++)
        {
            if (jiaoji[k] == a[i])
            {
                isJiao = true;
                break;
            }
        }
        if (isJiao) continue;
        for (int j = 0; j < len_b; j++)
        {
            if (a[i] == b[j])
            {
                jiaoji[jiaoidx] = a[i];
                jiaoidx++;
                break;
            }
        }
    }
    // 计算并集
    bool isBing;
    for (int i = 0; i < len_a; i++)
    {
        isBing = false;
        for (int k = 0; k < bingidx; k++)
        {
            if (bingji[k] == a[i])
            {
                isBing = true;
                break;
            }
        }
        if (!isBing)
        {
            bingji[bingidx] = a[i];
            bingidx++;
        }
    }
    for (int j = 0; j < len_b; j++)
    {
        isBing = false;
        for (int k = 0; k < bingidx; k++)
        {
            if (bingji[k] == b[j])
            {
                isBing = true;
                break;
            }
        }
        if (!isBing)
        {
            bingji[bingidx] = b[j];
            bingidx++;
        }
    }
    if (bingidx == 0) return 0.0;
    double result = (jiaoidx / 1.0) / (bingidx / 1.0);
    return result;
}
/**************** TODO-END ****************/