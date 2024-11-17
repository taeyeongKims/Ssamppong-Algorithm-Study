#include <iostream>
#include <vector>
using namespace std;

int len;

vector<vector<int> Cache;

int DP()
{
	int result = 1;
	for (int i = 0; i < len; i++)
	{
		result *= (len - i);
	}
	for (int i = 0; i < len - 1; i++)
	{
		result *= (len - i);
	}
	return result;
}

int main()
{
	cin >> len;
	
	cout << DP() << endl;
	return 0;

	// 빨간색을 먼저 배치 후, 파란색에 대한 교란순열 
}