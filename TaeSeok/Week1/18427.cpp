#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int N, M, H;
    cin >> N >> M >> H;
    cin.ignore();

    vector<vector<int>> blocks(N);
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);

        istringstream iss(line);
        int height;
        while (iss >> height)
            blocks[i].push_back(height);
    }

    // dp[i][h] = i번째 학생까지 사용해서 높이 h를 만드는 경우의 수
    vector<vector<int>> dp(N + 1, vector<int>(H + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int h = 0; h <= H; h++)
        {
            dp[i][h] = dp[i - 1][h];
            for (int block : blocks[i - 1])
                if (h >= block)
                    dp[i][h] = (dp[i][h] + dp[i - 1][h - block]) % 10007;
        }
    }

    cout << dp[N][H];

    return 0;
}
