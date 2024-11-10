#include <iostream>
#include <vector>
using namespace std;

int R, C, N;
vector<vector<bool>> bombPos;


vector<vector<bool>> explode(const vector<vector<bool>>& bombPos) 
{
    vector<vector<bool>> after(R + 1, vector<bool>(C + 1, true));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (bombPos[i][j]) {
                after[i][j] = false;
                if (i + 1 <= R) after[i + 1][j] = false;
                if (i - 1 >= 1) after[i - 1][j] = false;
                if (j + 1 <= C) after[i][j + 1] = false;
                if (j - 1 >= 1) after[i][j - 1] = false;
            }
        }
    }
    return after;
}

vector<vector<bool>> fillBomb() 
{
    return vector<vector<bool>>(R + 1, vector<bool>(C + 1, true));
}

int main() 
{
    cin >> R >> C >> N;

    bombPos = vector<vector<bool>>(R + 1, vector<bool>(C + 1, false));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            char input;
            cin >> input;
            if (input == 'O')
            {
                bombPos[i][j] = true;
            }
        }
    }

    vector<vector<bool>> result;
    if (N == 1) 
    {
        result = bombPos;
    }
    else if (N % 2 == 0) 
    {
        result = fillBomb();
    }
    else if (N % 4 == 3) 
    {
        result = explode(bombPos);
    }
    else if (N % 4 == 1) 
    {
        vector<vector<bool>> firstExplode = explode(bombPos);
        result = explode(firstExplode);
    }

    for (int i = 1; i <= R; i++) 
    {
        for (int j = 1; j <= C; j++) 
        {
            cout << (result[i][j] ? 'O' : '.');
        }
        cout << "\n";
    }
    return 0;
}
