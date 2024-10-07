#include <iostream>
using namespace std;

int N;
const int MOD = 1'000'000'007;
using int64 = long long int;

int64 factDP[100'001] = {};
int64 dp[100'001] = {};

int64 Factorial(int num)
{
	if (factDP[num] != -1)
	{
		return factDP[num];
	}

	if (num == 0)
	{
		return factDP[0] = 1;
	}

	return factDP[num] = (num * Factorial(num - 1)) % MOD;
}

int64 Solution(int num)
{
	if (dp[num] != -1)
	{
		return dp[num];
	}

	if (num == 0)
	{
		return dp[0] = 1;
	}

	if (num == 1)
	{
		return dp[1] = 0;
	}


	return dp[num] = ((num - 1) * (Solution(num - 1) + Solution(num - 2))) % MOD;
}

int main()
{
	cin >> N;
	::fill(&factDP[0], &factDP[0] + 100'001, -1);
	::fill(&dp[0], &dp[0] + 100'001, -1);

	cout << (Factorial(N) * Solution(N)) % MOD;

	return 0;
}