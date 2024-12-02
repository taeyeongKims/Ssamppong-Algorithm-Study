#include <iostream>
using namespace std;

long long dp[1000001] = { 0,  };
long long sum[1000001] = { 0,  };

const int MOD = 1'000'000'007;

int main()
{
    int N;
    cin >> N;

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;

    sum[0] = dp[0];
    sum[1] = (sum[0] + dp[1]) % MOD;
    sum[2] = (sum[1] + dp[2]) % MOD;

    for (int n = 3; n <= N; n++)
    {
        dp[n] = (dp[n - 1] * 2 + dp[n - 2] * 3 + sum[n - 3] * 2) % MOD;
        sum[n] = (sum[n - 1] + dp[n]) % MOD;
    }

    cout << dp[N] % MOD << endl;
    return 0;
}