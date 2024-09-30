#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 0;
	int r = 0;
	int l = 0;

	cin >> testCase;

	while (testCase--)
	{
		cin >> l >> r;

		if (r >= 4)
		{
			cout << r << "\n";
			continue;
		}

		int sum = 0;
		for (int i = r; i >= l; i--)
		{
			sum += (pow(2, i) * pow(10, r - i));
		}

		int cnt = 0;
		while (sum % 2 == 0)
		{
			sum /= 2;
			cnt++;
		}
		cout << cnt << "\n";
	}
}