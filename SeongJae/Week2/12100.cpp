#include <iostream>
#include <vector>
using namespace std;

int len;
int Max = 0;

void MoveLeft(vector<vector<int>>& arr) 
{
    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < len - 1; j++) 
        {
            int check = j + 1;
            while (check < len) 
            {
                if (arr[i][j] == arr[i][check] && arr[i][j] != 0)
                {
                    arr[i][j] += arr[i][check];
                    arr[i][check] = 0;
                    break;
                }
                else if (arr[i][check] == 0) 
                {
                    check += 1;
                }
                else {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < len; j++) 
        {
            int curr = j;
            while (curr > 0) 
            {
                if (arr[i][curr] != 0 && arr[i][curr - 1] == 0)
                {
                    swap(arr[i][curr], arr[i][curr - 1]);
                    curr -= 1;
                }
                else 
                {
                    break;
                }
            }
        }
    }
}

void MoveRight(vector<vector<int>>& arr) 
{
    for (int i = 0; i < len; i++) 
    {
        for (int j = len - 1; j > 0; j--) 
        { 
            int check = j - 1;
            while (check >= 0) 
            {
                if (arr[i][j] == arr[i][check] && arr[i][j] != 0) 
                {
                    arr[i][j] += arr[i][check];
                    arr[i][check] = 0;
                    break;
                }
                else if (arr[i][check] == 0) 
                {
                    check -= 1;
                }
                else 
                {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len; i++) 
    {
        for (int j = len - 1; j >= 0; j--)
        {
            int curr = j;
            while (curr < len - 1) 
            {
                if (arr[i][curr] != 0 && arr[i][curr + 1] == 0)
                {
                    swap(arr[i][curr], arr[i][curr + 1]);
                    curr += 1;
                }
                else 
                {
                    break;
                }
            }
        }
    }
}

void MoveTop(vector<vector<int>>& arr) 
{
    for (int i = 0; i < len - 1; i++) 
    {
        for (int j = 0; j < len; j++) 
        {
            int check = i + 1;
            while (check < len)
            {
                if (arr[i][j] == arr[check][j] && arr[i][j] != 0)
                {
                    arr[i][j] += arr[check][j];
                    arr[check][j] = 0;
                    break;
                }
                else if (arr[check][j] == 0) 
                {
                    check += 1;
                }
                else 
                {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < len; j++)
        {
            int curr = i;
            while (curr > 0) {
                if (arr[curr][j] != 0 && arr[curr - 1][j] == 0) 
                {
                    swap(arr[curr][j], arr[curr - 1][j]);
                    curr -= 1;
                }
                else 
                {
                    break;
                }
            }
        }
    }
}

void MoveBottom(vector<vector<int>>& arr)
{
    for (int i = len - 1; i > 0; i--)
    { 
        for (int j = 0; j < len; j++) 
        {
            int check = i - 1;
            while (check >= 0) 
            {
                if (arr[i][j] == arr[check][j] && arr[i][j] != 0) 
                {
                    arr[i][j] += arr[check][j];
                    arr[check][j] = 0;
                    break;
                }
                else if (arr[check][j] == 0) 
                {
                    check -= 1;
                }
                else {
                    break;
                }
            }
        }
    }
    for (int i = len - 1; i >= 0; i--) 
    {
        for (int j = 0; j < len; j++) 
        {
            int curr = i;
            while (curr < len - 1)
            {
                if (arr[curr][j] != 0 && arr[curr + 1][j] == 0) 
                {
                    swap(arr[curr][j], arr[curr + 1][j]);
                    curr += 1;
                }
                else 
                {
                    break;
                }
            }
        }
    }
}

void DFS(int rep, int index, vector<vector<int>>& arr) {
    rep += 1;

    switch (index) 
    {
    case 0:
        MoveLeft(arr);
        break;
    case 1:
        MoveRight(arr);
        break;
    case 2:
        MoveTop(arr);
        break;
    case 3:
        MoveBottom(arr);
        break;
    }

    if (rep == 5) 
    {
        for (int i = 0; i < len; i++) 
        {
            for (int j = 0; j < len; j++) 
            {
                Max = max(Max, arr[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> prevArr = arr; 
    for (int i = 0; i < 4; i++) 
    {
        DFS(rep, i, arr);
        arr = prevArr;
    }
}

int main() 
{
    cin >> len;
    vector<vector<int>> arr(len, vector<int>(len, 0));

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++) 
        {
            cin >> arr[i][j];
        }
    }

    Max = 0;
    vector<vector<int>> prev = arr;
    for (int i = 0; i < 4; i++) 
    {
        DFS(0, i, arr);
        arr = prev;
    }

    cout << Max << endl;
    return 0;
}
