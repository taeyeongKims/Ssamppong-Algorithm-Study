#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, R, C;

int Solution(int length)
{
	int x = 0;
	int y = 0;
	int curNum = 0;
	int step = 0;

	while (true)
	{
		if (x == C && y == R)
		{
			break;
		}

		int hLen = length * 0.5f;
		step = pow(2, 2 * (N - 1));
		--N;

		if (x + hLen <= C)
		{
			x = x + hLen;
			curNum += step;
		}

		if (y + hLen <= R)
		{
			y = y + hLen;
			curNum += step * 2;
		}

		length = hLen;
	}

	return curNum;
}
int main()
{
	cin >> N >> R >> C;
	cout << Solution(pow(2, N));

	return 0;
}
