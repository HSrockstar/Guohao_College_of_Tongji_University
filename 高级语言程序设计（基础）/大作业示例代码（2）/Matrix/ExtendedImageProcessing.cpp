#include "ExtendedImageProcessing.h"
#include <iostream>

Mat applyOtsuThreshold(const Mat &src) {
    if (src.empty()) {
        cout << "输入图像为空！" << endl;
        return Mat();
    }
    Mat gray, binary;
    if (src.channels() != 1)
        cvtColor(src, gray, COLOR_BGR2GRAY);
    else
        gray = src;
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    /*
cv::threshold(im_gray, img_bw, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
im_gray is a source 8-bit image,
img_bw is a result,
0 means threshold level which actually is omitted because we used CV_THRESH_OTSU flag,
255 is a value that is going to be assigned to respectively pixels in the result (namely, to all pixels which value in the source is greater then computed threshold level)
CV_THRESH_BINARY | CV_THRESH_OTSU is a required flag to perform Otsu thresholding. Because in fact we would like to perform binary thresholding, so we use CV_THRESH_BINARY (you can use any of 5 flags opencv provides) combined with CV_THRESH_OTSU
*/
    return binary;
}

Mat extractTarget(const Mat &src) {
    Mat binary = applyOtsuThreshold(src);
    if (binary.empty()) return Mat();
    
    std::vector<std::vector<Point>> contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    Mat mask = Mat::zeros(src.size(), CV_8UC1);
    if (!contours.empty()) {
        size_t maxIdx = 0;
        double maxArea = contourArea(contours[0]);
        for (size_t i = 1; i < contours.size(); i++) {
            double area = contourArea(contours[i]);
            if (area > maxArea) {
                maxArea = area;
                maxIdx = i;
            }
        }
        drawContours(mask, contours, static_cast<int>(maxIdx), Scalar(255), FILLED);
    }
    Mat result;
    src.copyTo(result, mask);
    return result;
}

void runOtsuAlgorithm() {
    cout << "请拖入图像文件或键入文件目录：" << endl;
    string str;
    cin >> str;
    cv::Mat src = cv::imread(str, cv::IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "无法加载图像，请确保图像路径正确。" << endl;
        return;
    }
    cv::Mat binary = applyOtsuThreshold(src);
    
    cv::namedWindow("Original Lena", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original Lena", src);
    cv::namedWindow("OTSU Result", cv::WINDOW_AUTOSIZE);
    cv::imshow("OTSU Result", binary);
    
    cout << "OTSU 算法处理完成，请在图像窗口中按任意键继续..." << endl;
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void runTargetExtraction() {
    cout << "请拖入图像文件或键入文件目录：" << endl;
    string str;
    cin >> str;
    cv::Mat src = cv::imread(str, cv::IMREAD_COLOR);
    if (src.empty()) {
        cout << "无法加载图像，请确保图像路径正确。" << endl;
        return;
    }
    cv::Mat target = extractTarget(src);
    
    cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original Image", src);
    cv::namedWindow("Extraction Result", cv::WINDOW_AUTOSIZE);
    cv::imshow("Extraction Result", target);
    
    cout << "目标提取处理完成，请在图像窗口中按任意键继续..." << endl;
    cv::waitKey(0);
    cv::destroyAllWindows();
}