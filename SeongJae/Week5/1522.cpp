#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();
    int A = 0;

    for (char c : s)
    {
        if (c == 'a')
        {
            A++;
        }
    }
    if (A == n)
    {
        cout << 0 << endl;
        return 0;
    }

    s += s;

    int currMin = n;
    int currB = 0;

    for (int i = 0; i < A; i++)
    {
        if (s[i] == 'b') currB++;
    }

    currMin = currB;
    for (int i = A; i < n + A; i++)
    {
        if (s[i] == 'b')
            currB++;
        if (s[i - A] == 'b')
            currB--;

        currMin = min(currMin, currB);
    }

    cout << currMin << endl;
    return 0;
}
