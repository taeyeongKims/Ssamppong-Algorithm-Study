#include <iostream>
#include <vector>
using namespace std;

int CoinCnt;
int TotalVal;

int main()
{
	cin >> CoinCnt >> TotalVal;

	int* CoinVal = new int[CoinCnt];
	int DP[100000] = { 0, };
	for (int i = 0; i < CoinCnt; i++)
	{
		int rep;	cin >> rep;
		CoinVal[i] = rep;
	}
	DP[0] = 1;

	for (int i = 0; i < CoinCnt; i++)
	{
		for (int j = 1; j <= TotalVal; j++)
		{
			if (j - CoinVal[i] >= 0)
				DP[j] = DP[j] + DP[j - CoinVal[i]];
		}
	}
	cout << DP[TotalVal] << endl;
	return 0;
}