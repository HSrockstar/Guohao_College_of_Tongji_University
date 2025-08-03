#pragma once
#ifndef ROUND_BUTTON_H
#define ROUND_BUTTON_H

#include <graphics.h>

//������Բ�Ǿ��ΰ�ť�ṹ�壬�������ѡ����õ�Բ�Ǿ���
//anyway�ҷ��ַ�װ֮���ظ�����ĺ�ˬ����ᵽ��ʲô�и�����
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