#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// ¿¼º´  
int DP[51][1001];
vector<int> block[51];
int main() {
    cin.tie(0); 
    cout.tie(0); 
    ios::sync_with_stdio(false);

    int Std, Block, Hei;
    cin >> Std >> Block >> Hei;
    cin.ignore();
    for (int i = 1; i <= Std; i++) 
    {
        string str;
        getline(cin, str);

        stringstream sstr(str);
        int num;

        while (sstr >> num)
        {
            block[i].push_back(num);
        }
    }
    for (int i = 0; i <= Std; i++) 
    {
        DP[i][0] = 1;
    }
    for (int i = 1; i <= Std; i++) 
    {
        for (int j = 1; j <= Hei; j++) 
        {
            for (int k = 0; k < block[i].size(); k++) 
            {
                if (j >= block[i][k]) DP[i][j] = (DP[i][j] + DP[i - 1][j - block[i][k]]) % 10007;
            }
            DP[i][j] = (DP[i][j] + DP[i - 1][j]) % 10007;
        }
    }

    cout << DP[Std][Hei];
    return 0;
}