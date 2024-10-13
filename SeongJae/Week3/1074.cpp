#include <iostream>
#include <cmath>
using namespace std;

using ll = long long int;
ll num;

int row, col;

ll function(ll len, ll x, ll y, ll& curr)
{
    if (len > 2)
    {
        if (row < x + len / 2 && col < y + len / 2) 
        {
            return function(len / 2, x, y, curr);
        }
        else if (row < x + len / 2 && col >= y + len / 2) 
        {
            curr += (len / 2) * (len / 2);
            return function(len / 2, x, y + len / 2, curr);
        }
        else if (row >= x + len / 2 && col < y + len / 2) 
        {
            curr += 2 * (len / 2) * (len / 2);
            return function(len / 2, x + len / 2, y, curr);
        }
        else 
        {
            curr += 3 * (len / 2) * (len / 2);
            return function(len / 2, x + len / 2, y + len / 2, curr);
        }
    }
    else
    {
        if (x == row && y == col) return curr;
        if (x == row && y + 1 == col) return curr + 1;
        if (x + 1 == row && y == col) return curr + 2;
        return curr + 3;
    }
}

int main()
{
    cin >> num >> row >> col;

    ll len = pow(2, num);
    ll curr = 0;
    ll result = function(len, 0, 0, curr);
    cout << result << endl;
    return 0;
}
