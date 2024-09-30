#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> board = {};
int maxValue = -1;
int N;

enum Direction
{
    DR_LEFT = 0,
    DR_DOWN,
    DR_RIGHT,
    DR_UP,

    DR_COUNT
};

int dx[DR_COUNT] = { -1, 0, 1, 0 };
int dy[DR_COUNT] = { 0, 1, 0, -1 };

inline bool IsOutOfBound(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= N;
}

void MoveBlock(Direction inDir, int curX, int curY, vector<vector<bool>>& merged)
{
    int curNum = board[curY][curX];
    if (curNum == 0) return; 

    while (true)
    {
        int nextX = curX + dx[inDir];
        int nextY = curY + dy[inDir];

        if (IsOutOfBound(nextX, nextY))
            break;

        int nextNum = board[nextY][nextX];

        if (nextNum == 0)
        {
            board[nextY][nextX] = board[curY][curX];
            board[curY][curX] = 0;
            curX = nextX;
            curY = nextY;
        }
        else if (nextNum == board[curY][curX] && !merged[nextY][nextX] && !merged[curY][curX])
        {
            board[nextY][nextX] = board[curY][curX] * 2;
            board[curY][curX] = 0;
            merged[nextY][nextX] = true; 
            break;
        }
        else
        {
            break;
        }
    }
}

void MoveRow(Direction inDir, int row, vector<vector<bool>>& merged)
{
    if (inDir == DR_LEFT)
    {
        for (int i = 0; i < N; i++)
        {
            MoveBlock(inDir, i, row, merged);
        }
    }
    else if (inDir == DR_RIGHT)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            MoveBlock(inDir, i, row, merged);
        }
    }
}

void MoveCol(Direction inDir, int col, vector<vector<bool>>& merged)
{
    if (inDir == DR_UP)
    {
        for (int i = 0; i < N; i++)
        {
            MoveBlock(inDir, col, i, merged);
        }
    }
    else if (inDir == DR_DOWN)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            MoveBlock(inDir, col, i, merged);
        }
    }
}

void DoSlide(Direction inDir)
{
    vector<vector<bool>> merged(N, vector<bool>(N, false));

    switch (inDir)
    {
    case DR_LEFT:
        for (int i = 0; i < N; i++)
        {
            MoveRow(inDir, i, merged);
        }
        break;
    case DR_DOWN:
        for (int i = 0; i < N; i++)
        {
            MoveCol(inDir, i, merged);
        }
        break;
    case DR_RIGHT:
        for (int i = 0; i < N; i++)
        {
            MoveRow(inDir, i, merged);
        }
        break;
    case DR_UP:
        for (int i = 0; i < N; i++)
        {
            MoveCol(inDir, i, merged);
        }
        break;
    }
}

void Solution(int num)
{
    if (num == 5)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                maxValue = max(maxValue, board[i][j]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        vector<vector<int>> save = board;
        DoSlide((Direction)i);         
        Solution(num + 1);                 
        board = save;                     
    }
}

int main()
{
    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            board[i][j] = num;
        }
    }

    Solution(0);
    cout << maxValue << endl;
    return 0;
}
