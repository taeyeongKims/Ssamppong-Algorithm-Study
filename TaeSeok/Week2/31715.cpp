#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1'000'000'007

long long Factorial(int n) 
{
    long long result = 1;
    for (int i = 2; i <= n; ++i) 
        result = (result * i) % MOD;
    
    return result;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;

    vector<vector<int>> seats(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            int h;
            cin >> h;
            seats[i][j] = h + i * D;
        }
        sort(seats[i].begin(), seats[i].end());
    }

    long long fact_M = Factorial(M);
    long long result = fact_M;

    for (int i = 0; i < N - 1; i++) 
    {
        vector<int> counts(M, 0);

        for (int j = 0; j < M; j++) 
            counts[j] = M - (upper_bound(seats[i + 1].begin(), seats[i + 1].end(), seats[i][j]) - seats[i + 1].begin());
        

        if (counts.back() == M) 
        {
            result = (result * fact_M) % MOD;
            continue;
        }

        long long ret = 1;
        for (int t = 0; t < M; t++) {
            if (counts[M - (t + 1)] - t > 0) 
                ret = (ret * (counts[M - (t + 1)] - t)) % MOD;
            else 
            {
                ret = 0; 
                break;
            }
        }
        result = (result * ret) % MOD;
    }

    cout << result;
    return 0;
}
