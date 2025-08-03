#include "RoundButton.h"

//��������û����ͣ�ڰ�ť��
bool RoundButton::isHovered(int mx, int my) const
{
    return mx >= left && mx <= right && my >= top && my <= bottom;
}

//���ư�ť
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

//��������û�е����ť
bool RoundButton::isClicked(int x, int y) const
{
    return isHovered(x, y);
}