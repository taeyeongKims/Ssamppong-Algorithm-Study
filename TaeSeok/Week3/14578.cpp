#include <iostream>
#include <vector>
using namespace std;

#define MOD 1'000'000'007

int N;
vector<long long> fact;
vector<long long> der;

void Factorial(int n)
{
	fact.resize(n + 1);
	fact[0] = 1;
	for (size_t i = 1; i <= N; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}

void Derangement(int n)
{
	der.resize(n + 1);
	der[0] = 1;
	der[1] = 0;

	for (int i = 2; i <= N ; i++)
	{
		der[i] = ((i - 1) * (der[i - 1] + der[i - 2])) % MOD;
	}
}

int main()
{
	cin >> N;
	Factorial(N);
	Derangement(N);

	cout << (fact[N] * der[N]) % MOD;

	return 0;
}
