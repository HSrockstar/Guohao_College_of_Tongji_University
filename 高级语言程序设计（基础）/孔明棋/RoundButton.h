#pragma once
#ifndef ROUND_BUTTON_H
#define ROUND_BUTTON_H

#include <graphics.h>

//定义了圆角矩形按钮结构体，本程序的选项都是用的圆角矩形
//anyway我发现封装之后重复用真的好爽，体会到了什么叫复用性
struct RoundButton
{
    int left, top, right, bottom;
    int rx, ry;
    COLORREF borderColor;
    COLORREF fillColor;
    COLORREF hoverBorderColor;
    COLORREF hoverFillColor;
    COLORREF textColor;
    TCHAR label[50];
    int fontSize;
    TCHAR fontName[50];

    bool isHovered(int mx, int my) const;
    void draw(int mouseX = -1, int mouseY = -1) const;
    bool isClicked(int x, int y) const;
};

#endif // ROUND_BUTTON_H