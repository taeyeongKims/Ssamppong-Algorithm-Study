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
    if (curNum == 0) return;  // 빈칸은 처리하지 않음

    while (true)
    {
        int nextX = curX + dx[inDir];
        int nextY = curY + dy[inDir];

        // 2.1: 범위 밖이면 중단
        if (IsOutOfBound(nextX, nextY))
            break;

        int nextNum = board[nextY][nextX];

        // 2.2.3: 앞에 0이 있으면 이동
        if (nextNum == 0)
        {
            board[nextY][nextX] = board[curY][curX];
            board[curY][curX] = 0;
            curX = nextX;
            curY = nextY;
        }
        // 2.2.1: 앞에 같은 숫자, 합쳐진 적 없음 -> 합체
        else if (nextNum == board[curY][curX] && !merged[nextY][nextX] && !merged[curY][curX])
        {
            board[nextY][nextX] = board[curY][curX] * 2;
            board[curY][curX] = 0;
            merged[nextY][nextX] = true;  // 합체된 위치 표시
            break;
        }
        // 2.2.2: 이동 불가
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
    // 합체 여부를 추적하기 위한 2차원 배열
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
        // 보드에서 최대값 갱신
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
        vector<vector<int>> save = board;  // 현재 보드 상태 저장
        DoSlide((Direction)i);             // 각 방향으로 슬라이드
        Solution(num + 1);                 // 재귀 호출로 다음 단계 진행
        board = save;                      // 보드 상태 복원
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
