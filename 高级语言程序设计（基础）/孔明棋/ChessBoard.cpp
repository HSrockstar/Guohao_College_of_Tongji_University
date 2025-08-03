#include "ChessBoard.h"

const int cell_size = 70;
const int offset_x = 267;
const int offset_y = 116;

//���ո�����init��ʼ������
//֮����Ҫ����init��Ϊ������о�
void ChessBoard::reset(int init[7][7])
{
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            board[i][j] = init[i][j];
            history[i][j] = init[i][j];
        }
    }
    step = 0;
}

//�ж����޿��ƶ����ӣ���Ϸ�Ƿ����
bool ChessBoard::canMove() const
{
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (board[i][j] == 1)
            {
                int dx[4] = { 0, 0, -1, 1 };
                int dy[4] = { -1, 1, 0, 0 };
                for (int d = 0; d < 4; ++d)
                {
                    int ni = i + dy[d] * 2;
                    int nj = j + dx[d] * 2;
                    int mi = i + dy[d];
                    int mj = j + dx[d];
                    if (ni >= 0 && ni < 7 && nj >= 0 && nj < 7 &&
                        board[ni][nj] == 0 && board[mi][mj] == 1)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//�洢һ����ʷ�����ڻ��壨����һ��ֻ�ܻ���һ����
void ChessBoard::restoreHistory()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = history[i][j];
        }
    }
}

//��������
void ChessBoard::draw(const IMAGE& img, int selected_x, int selected_y)
{
    cleardevice();
    putimage(0, 0, &img);

    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (board[i][j] == -1) continue;

            int x = offset_x + j * cell_size;
            int y = offset_y + i * cell_size;

            setlinecolor(BLACK);
            setfillcolor(RGB(200, 180, 140));
            fillcircle(x, y, 30);

            if (board[i][j] == 1)
            {
                setfillcolor(RGB(50, 100, 255));
            }

            if (selected_x == j && selected_y == i)
            {
                setfillcolor(RGB(255, 100, 100));
            }

            if (board[i][j] == 1 || (selected_x == j && selected_y == i))
            {
                fillcircle(x, y, 25);
            }
        }
    }

    setlinecolor(WHITE);
    setfillcolor(RGB(180, 230, 250));
    solidrectangle(845, 541, 945, 641);

    setbkmode(TRANSPARENT);
    settextstyle(40, 0, _T("����"));
    settextcolor(BLACK);

    int count = countPieces();
    TCHAR text[10];
    _stprintf_s(text, _T("%d"), count);

    outtextxy(875, 571, text);

    FlushBatchDraw();
}

//ֻ�����ƶ����ӣ��ж��ܷ��ƶ��Ĳ�����play_game������
bool ChessBoard::move(int sx, int sy, int dx, int dy)
{
    int mx = (sx + dx) / 2;
    int my = (sy + dy) / 2;
    if (board[dy][dx] == 0 && board[my][mx] == 1)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                history[i][j] = board[i][j];
            }
        }
        board[sy][sx] = 0;
        board[my][mx] = 0;
        board[dy][dx] = 1;
        return true;
    }
    return false;
}

//��ȡ����״̬
int ChessBoard::getCell(int i, int j) const
{
    return board[i][j];
}

//���㵱ǰ���������Ӹ�������ʵ����ֱ�Ӹĳ�32-step�����Ǹо���̫�Ƚ������׳����⣩
int ChessBoard::countPieces() const
{
    int count = 0;
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (board[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}