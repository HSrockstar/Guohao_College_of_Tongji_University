#include "ImageProcessing.h"
#include <iostream>

void convolutionApplication() {
    cout << "请拖入图像文件或键入文件目录：" << endl;
    string str;
    cin >> str;
    Mat src = imread(str, IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "无法加载图像，请确保图像路径正确。" << endl;
        return;
    }
    vector<Mat> kernels;
    Mat B1 = (Mat_<float>(3, 3) << 1, 1, 1,
                                   1, 1, 1,
                                   1, 1, 1);
    kernels.push_back(B1);
    Mat B2 = (Mat_<float>(3, 3) << -1, -2, -1,
                                    0,  0,  0,
                                    1,  2,  1);
    kernels.push_back(B2);
    Mat B3 = (Mat_<float>(3, 3) << -1,  0,  1,
                                   -2,  0,  2,
                                   -1,  0,  1);
    kernels.push_back(B3);
    Mat B4 = (Mat_<float>(3, 3) << -1, -1, -1,
                                   -1,  9, -1,
                                   -1, -1, -1);
    kernels.push_back(B4);
    Mat B5 = (Mat_<float>(3, 3) << -1, -1,  0,
                                   -1,  0,  1,
                                    0,  1,  1);
    kernels.push_back(B5);
    Mat B6 = (Mat_<float>(3, 3) << 1, 2, 1,
                                    2, 4, 2,
                                    1, 2, 1);
    kernels.push_back(B6);
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", src);

    for (int i = 0; i < kernels.size(); i++) {
        Mat kernel = kernels[i];
        float kernelSum = sum(kernel)[0];
        Mat normKernel;
        if (kernelSum != 0) {
            normKernel = kernel / kernelSum;
        } else {
            normKernel = kernel;
        }
        Mat dst;
        filter2D(src, dst, -1, normKernel, Point(-1, -1), 0, BORDER_DEFAULT);
        /*
// Apply filter
filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
The arguments denote:
src: Source image
dst: Destination image
ddepth: The depth of dst. A negative value (such as −1) indicates that the depth is the same as the source.
kernel: The kernel to be scanned through the image
anchor: The position of the anchor relative to its kernel. The location Point(-1, -1) indicates the center by default.
delta: A value to be added to each pixel during the correlation. By default it is 0
BORDER_DEFAULT: We let this value by default (more details in the following tutorial)
*/
        string windowName = "Kernel B" + to_string(i + 1);
        namedWindow(windowName, WINDOW_AUTOSIZE);
        imshow(windowName, dst);
    }

    cout << "图像处理完成，请在图像窗口中按任意键继续..." << endl;
    waitKey(0);
    destroyAllWindows();
}