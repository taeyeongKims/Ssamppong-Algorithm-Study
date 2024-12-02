#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    string s;
    cin >> s;

    int n = s.length();
    int a_count = count(s.begin(), s.end(), 'a'); 

    s += s;

    int min_b_count = n;
    int current_b_count = 0;

    for (int i = 0; i < a_count; ++i)
        if (s[i] == 'b') 
            ++current_b_count;

    min_b_count = current_b_count;

    for (int i = 1; i < n; ++i)
    {
        if (s[i - 1] == 'b') 
            --current_b_count;
        if (s[i + a_count - 1] == 'b')
            ++current_b_count;

        min_b_count = min(min_b_count, current_b_count);
    }

    cout << min_b_count << endl;
    return 0;
}
