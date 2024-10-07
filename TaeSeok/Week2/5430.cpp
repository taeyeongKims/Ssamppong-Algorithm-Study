#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int T, n;
string p, line, token;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> p >> n;
        cin >> line;
        vector<int> v;
        if (line.size() > 2)
        {
            line = line.substr(1, line.size() - 2);
            stringstream ss(line);
            while (getline(ss, token, ','))
                v.push_back(stoi(token));
        }
        bool isValid = true;
        bool isReversed = false;
        int start = 0;
        for (int idx = 0; idx < p.length(); idx++)
        {
            if (p[idx] == 'R')
                isReversed = !isReversed;
            else if (p[idx] == 'D')
            {
                if (v.empty() || start == v.size())
                {
                    cout << "error" << '\n';
                    isValid = false;
                    break;
                }
                if (isReversed) v.pop_back();
                else start++;
            }
        }
        if (!isValid) continue;

        cout << "[";
        if (!isReversed)
        {
            if (start < v.size()) {
                cout << v[start++];
                while (start < v.size())
                    cout << "," << v[start++];
            }
        }
        else
        {
            if (!v.empty() && start < v.size()) {
                cout << v.back();
                for (int i = v.size() - 2; i >= start; i--)
                    cout << "," << v[i];
            }
        }
        cout << "]" << '\n';
    }
    return 0;
}