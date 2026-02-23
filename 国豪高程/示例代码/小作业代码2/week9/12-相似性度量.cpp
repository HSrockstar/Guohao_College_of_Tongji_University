//#include <iostream>
//using namespace std;
//
//// 余弦相似度
//double cosine_similarity(double a[], double b[], int n);
//// 距离度量（欧几里得/曼哈顿/汉明）
//double distance(double a[], double b[], int n, const char type[] = "Euclidean");
//double distance(char a[], char b[], const char type[]);
//// 杰卡德相似系数
//double jaccard_similarity_coefficient(char a[], char b[]);
//
//int main()
//{
//    // 1. 余弦相似度
//
//    // 数据格式：两个三维向量
//    {
//        double a[3] = {};
//        double b[3] = {};
//        cout << "------------------------------------------" << endl;
//        cout << "             Cosine Similarity            " << endl;
//        cout << "------------------------------------------" << endl;
//        cout << "Please input the first vector: " << endl;
//        for (int i = 0; i < 3; i++)
//        {
//            cin >> a[i];
//        }
//        cout << "Please input the second vector: " << endl;
//        for (int i = 0; i < 3; i++)
//        {
//            cin >> b[i];
//        }
//        cout << "The cosine similarity is: " << cosine_similarity(a, b, 3) << endl;
//    }
//
//    // 2. 欧几里得距离
//
//    // 数据格式：两个三维坐标
//    {
//        double a[3] = {};
//        double b[3] = {};
//        cout << "------------------------------------------" << endl;
//        cout << "           Euclidean Distance             " << endl;
//        cout << "------------------------------------------" << endl;
//        cout << "Please input the first vector: " << endl;
//        for (int i = 0; i < 3; i++)
//        {
//            cin >> a[i];
//        }
//        cout << "Please input the second vector: " << endl;
//        for (int i = 0; i < 3; i++)
//        {
//            cin >> b[i];
//        }
//        cout << "The euclidean distance is: " << distance(a, b, 3) << endl;
//        // cout << "The euclidean distance is: " << distance(a, b, 3, "Euclidean") << endl;
//    }
//
//    // 3. 曼哈顿距离
//
//    // 数据格式：两个三维坐标
//    {
//        double a[3] = {};
//        double b[3] = {};
//        cout << "------------------------------------------" << endl;
//        cout << "           Manhattan Distance             " << endl;
//        cout << "------------------------------------------" << endl;
//        cout << "Please input the first vector: " << endl;
//        for (int i = 0; i < 3; i++)
//        {
//            cin >> a[i];
//        }
//        cout << "Please input the second vector: " << endl;
//        for (int i = 0; i < 3; i++)
//        {
//            cin >> b[i];
//        }
//        cout << "The manhattan distance is: " << distance(a, b, 3, "Manhattan") << endl;
//    }
//
//    // 4. 汉明距离
//
//    // 数据格式：两个字符串
//    {
//        char a[100] = {};
//        char b[100] = {};
//        cout << "------------------------------------------" << endl;
//        cout << "            Hamming Distance              " << endl;
//        cout << "------------------------------------------" << endl;
//        cout << "Please input the first string: " << endl;
//        cin.get(); // 读取换行符（cin.getline()之前需要先读取换行符，否则会直接读取换行符，导致输入错误）
//        cin.getline(a, 100);
//        cout << "Please input the second string: " << endl;
//        cin.getline(b, 100);
//        cout << "The hamming distance is: " << distance(a, b, "Hamming") << endl;
//    }
//
//    // 5. 杰卡德相似系数
//
//    // 数据格式：两个小写字母集合（非空），已经按照字典序排好序
//    {
//        char a[100] = {};
//        char b[100] = {};
//        cout << "------------------------------------------" << endl;
//        cout << "       Jaccard Similarity Coefficient     " << endl;
//        cout << "------------------------------------------" << endl;
//        cout << "Please input the first set: " << endl;
//        cin >> a;
//        cout << "Please input the second set: " << endl;
//        cin >> b;
//        cout << "The jaccard similarity coefficient is: " << jaccard_similarity_coefficient(a, b) << endl;
//    }
//
//    return 0;
//}
//
///****************** TODO ******************/
//// 余弦相似度
//double cosine_similarity(double a[], double b[], int n)
//{
//    double inner_product = 0.0, square_a = 0.0, square_b = 0.0;
//
//    for (int i = 0; i < n; i++)
//    {
//        inner_product = inner_product + a[i] * b[i];
//        square_a = square_a + a[i] * a[i];
//        square_b = square_b + b[i] * b[i];
//    }
//
//    double result = inner_product / (sqrt(square_a) * sqrt(square_b));
//    return result;
//}
//
//// 距离度量（欧几里得/曼哈顿/汉明）
//double distance(double a[], double b[], int n, const char type[])
//{
//    double result = 0.0;
//
//    if (strcmp(type, "Euclidean") == 0)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            result = result + (a[i] - b[i]) * (a[i] - b[i]);
//        }
//        result = sqrt(result);
//        return result;
//    }
//
//    else if (strcmp(type, "Manhattan") == 0)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            result = result + fabs(a[i] - b[i]);
//        }
//        return result;
//    }
//}
//
//double distance(char a[], char b[], const char type[])
//{
//    if (strcmp(type, "Hamming") == 0)
//    {
//        int len = static_cast<int>(strlen(a));
//
//        double result = 0.0;
//        for (int i = 0; i < len; i++)
//        {
//            if (a[i] != b[i])
//                result++;
//        }
//        return result;
//    }
//}
//
//// 杰卡德相似系数
//double jaccard_similarity_coefficient(char a[], char b[])
//{
//    int len_a = static_cast<int>(strlen(a));
//    int len_b = static_cast<int>(strlen(b));
//    int i = 0, j = 0;
//    double intersection = 0.0;
//
//    while (i < len_a && j < len_b)
//    {
//        if (a[i] == b[j])
//        {
//            intersection++;
//            i++;
//            j++;
//        }
//        else if (a[i] < b[j])
//        {
//            i++;
//        }
//        else
//        {
//            j++;
//        }
//    }
//
//    int count = len_a + len_b - intersection;
//    double result = intersection / count;
//    return result;
//}
//
///**************** TODO-END ****************/