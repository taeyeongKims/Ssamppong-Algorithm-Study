#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;
int board[SIZE][SIZE];
int paperCount[6] = { 0, 5, 5, 5, 5, 5 };
int minPapers = INT32_MAX;

bool canAttach(int x, int y, int size)
{
    if (x + size > SIZE || y + size > SIZE) 
        return false;

    for (int i = x; i < x + size; ++i) 
    {
        for (int j = y; j < y + size; ++j) 
        {
            if (board[i][j] != 1) 
                return false; 
        }
    }
    return true;
}

void attach(int x, int y, int size, int value)
{
    for (int i = x; i < x + size; ++i) 
    {
        for (int j = y; j < y + size; ++j) 
        {
            board[i][j] = value; 
        }
    }
}

void Sol(int x, int y, int usedPapers)
{
    if (x >= SIZE) 
    {
        minPapers = min(minPapers, usedPapers);
        return;
    }

    if (y >= SIZE) 
    {
        Sol(x + 1, 0, usedPapers); 
        return;
    }

    if (board[x][y] == 0) 
    {
        Sol(x, y + 1, usedPapers);
        return;
    }

    for (int size = 1; size <= 5; ++size) 
    {
        if (paperCount[size] > 0 && canAttach(x, y, size)) 
        {
            attach(x, y, size, 0); 
            paperCount[size]--;
            Sol(x, y + 1, usedPapers + 1);
            paperCount[size]++;
            attach(x, y, size, 1); 
        }
    }
}

int main()
{
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            cin >> board[i][j];
        }
    }

    Sol(0, 0, 0);

    cout << (minPapers == INT32_MAX ? -1 : minPapers) << endl;

    return 0;
}
