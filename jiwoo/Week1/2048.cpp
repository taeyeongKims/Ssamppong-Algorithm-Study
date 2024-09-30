#include <iostream>
using namespace std;

int cache[4][4] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cache[0][0] = 0;
	cache[0][1] = 2;
	cache[0][2] = 2;
	cache[0][3] = 5;

	cache[1][1] = 1;
	cache[1][2] = 3;
	cache[1][3] = 3;

	cache[2][2] = 2;
	cache[2][3] = 4;

	cache[3][3] = 3;

	int t;
	cin >> t;

	while(t--)
	{
		int l, r;
		cin >> l >> r;
		
		if (r > 3)
		{
			cout << r << '\n';
		}
		else
		{
			cout << cache[l][r] << '\n';
		}
	}
}