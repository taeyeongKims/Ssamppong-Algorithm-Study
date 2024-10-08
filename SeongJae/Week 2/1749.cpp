#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MIN_NUM -2147483647

vector<vector<int>> Cache;

int main() 
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> Info(rows + 1, vector<int>(cols + 1, 0));
    Cache = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= cols; j++) 
        {
            int num;
            cin >> num;
            Info[i][j] = num;
        }
    }

    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= cols; j++) 
        {
            Cache[i][j] = Cache[i - 1][j] + Cache[i][j - 1] - Cache[i - 1][j - 1] + Info[i][j];
        }
    }

    int Max = MIN_NUM;

    for (int x1 = 1; x1 <= rows; x1++) 
    {
        for (int y1 = 1; y1 <= cols; y1++) 
        {
            for (int x2 = x1; x2 <= rows; x2++) 
            {
                for (int y2 = y1; y2 <= cols; y2++) 
                {
                    int subMatrixSum = 0;
                    subMatrixSum += Cache[x2][y2];
                    if (x1 > 1) 
                    {
                        subMatrixSum -= Cache[x1 - 1][y2];
                    }
                    if (y1 > 1) 
                    {
                        subMatrixSum -= Cache[x2][y1 - 1];
                    }
                    if (x1 > 1 && y1 > 1) 
                    {
                        subMatrixSum += Cache[x1 - 1][y1 - 1];
                    }
                    Max = max(Max, subMatrixSum);
                }
            }
        }
    }

    cout << Max << endl;

    return 0;
}