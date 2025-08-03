#include "RoundButton.h"

//检测鼠标有没有悬停在按钮上
bool RoundButton::isHovered(int mx, int my) const
{
    return mx >= left && mx <= right && my >= top && my <= bottom;
}

//绘制按钮
void RoundButton::draw(int mouseX, int mouseY) const
{
    bool hovered = isHovered(mouseX, mouseY);
    setlinecolor(hovered ? hoverBorderColor : borderColor);
    setfillcolor(hovered ? hoverFillColor : fillColor);
    solidroundrect(left, top, right, bottom, rx, ry);

    setbkmode(TRANSPARENT);
    settextcolor(textColor);
    settextstyle(fontSize, 0, fontName);

    int w = textwidth(label);
    int h = textheight(label);
    int x = (left + right - w) / 2;
    int y = (top + bottom - h) / 2;

    outtextxy(x, y, label);
}

//检测鼠标有没有点击按钮
bool RoundButton::isClicked(int x, int y) const
{
    return isHovered(x, y);
}