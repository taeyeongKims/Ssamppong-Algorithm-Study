#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 10;
int grid[SIZE][SIZE];
int paper[6] = { 0, 5, 5, 5, 5, 5 }; 
int minCount = INT32_MAX;

bool CanPlace(int x, int y, int size) 
{
    if (x + size > SIZE || y + size > SIZE) return false;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++) 
        {
            if (grid[i][j] != 1) return false;
        }
    }
    return true;
}

void SetPaper(int x, int y, int size, int value) 
{
    for (int i = x; i < x + size; i++) 
    {
        for (int j = y; j < y + size; j++)
        {
            grid[i][j] = value;
        }
    }
}

void Solve(int x, int y, int count) 
{
    if (x >= SIZE)
    {
        minCount = min(minCount, count);
        return;
    }
    if (y >= SIZE)
    {
        Solve(x + 1, 0, count);
        return;
    }
    if (grid[x][y] == 0)
    {
        Solve(x, y + 1, count);
        return;
    }

    for (int size = 5; size >= 1; size--)
    {
        if (paper[size] > 0 && CanPlace(x, y, size))
        {
            paper[size]--;
            SetPaper(x, y, size, 0);
            Solve(x, y + 1, count + 1);
            SetPaper(x, y, size, 1);
            paper[size]++;
        }
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) 
        {
            cin >> grid[i][j];
        }
    }

    Solve(0, 0, 0);
    cout << (minCount == INT32_MAX ? -1 : minCount) << endl;
    return 0;
}
