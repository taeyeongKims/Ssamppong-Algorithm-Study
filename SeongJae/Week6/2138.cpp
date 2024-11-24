#include <iostream> 
#include <vector> 
using namespace std;

int ans = -1;
int N;
string str1, str2;


char change(char c)
{
    if (c == '0')
        return '1';
    else
        return '0';
}

void solve(string& s, int cnt, int x)
{

    if (x == N) 
    {
        if (s[x - 1] == str2[x - 1])
        {
            if (ans == -1) ans = cnt;
            else ans = min(ans, cnt);
        }
        return;
    }
    if (s[x - 1] == str2[x - 1])
        solve(s, cnt, x + 1);
    else 
    {
        s[x - 1] = change(s[x - 1]);
        s[x] = change(s[x]);
        if (s[x + 1] != N)
            s[x + 1] = change(s[x + 1]);

        solve(s, cnt + 1, x + 1);
    }
    return;
}


int main() {

    cin >> N;
    cin >> str1 >> str2;

    string tmp = str1;

    solve(str1, 0, 1);

    if (ans == -1)
    {
        str1 = tmp;
        str1[0] = change(str1[0]);
        str1[1] = change(str1[1]);
        solve(str1, 1, 1);
    }
    cout << ans;
    return 0;
}