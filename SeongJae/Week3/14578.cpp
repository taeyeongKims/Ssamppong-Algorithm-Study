#include <iostream>
#include <vector>

using namespace std;

using ll = long long int;
ll len;

vector<long long int> Cache;



int main()
{
	cin >> len;

	ll result = 1;
	Cache = vector<ll>(len + 1, 0);
	Cache[1] = 0;
	Cache[0] = 1;
	for (int i = 2; i <= len; i++)
	{
		result *= i;
		result %= 1000000007;
		Cache[i] = (i - 1) * (Cache[i - 1] + Cache[i - 2]) % 1000000007;
	}

	cout << Cache[len] * result % 1000000007;

	return 0;

	// 빨간색을 먼저 배치 후, 파란색에 대한 교란순열 
}