#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int t; 
    cin >> t;

    vector<int> dp(10001, 0);

    dp[0] = 1; 

    for (int i = 1; i <= 3; ++i)
        for (int j = i; j <= 10000; ++j)
            dp[j] += dp[j - i];

    while (t--) 
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}