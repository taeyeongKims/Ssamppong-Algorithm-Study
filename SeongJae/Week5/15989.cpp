#include <iostream>
using namespace std;
#include <vector>
vector<vector<int>> Cache;
int C;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> C;

	for (int i = 0; i < C; i++)
	{
		Cache = vector<vector<int>>(10001, vector<int>(4, 0));
		int num; cin >> num;

		Cache[0][1] = 1;
		Cache[1][1] = 1;
		for (int i = 2; i <= 10000; i++)
		{
			Cache[i][1] = Cache[i - 1][1];

			Cache[i][2] = Cache[i - 2][1] + Cache[i - 2][2];

			if (i >= 3)
			{
				Cache[i][3] = Cache[i - 3][1] + Cache[i - 3][2] + Cache[i - 3][3];
			}
		}

		cout << Cache[num][1] + Cache[num][2] + Cache[num][3] << endl;

	}
	return 0;
}