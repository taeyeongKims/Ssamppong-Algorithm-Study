#include <iostream>

#include <cmath>
using namespace std;

string num;

// 시간초과 시발 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int Case;
	cin >> Case;

	int total;
	int Count;
	for (int i = 0; i < Case; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;

		if (num2 >= 4)
		{
			printf("%d\n", num2);
			continue;
		}

		total = 0;
		for (int i = num2; i >= num1; i--)
		{
			total += (pow(2, i) * pow(10, num2 - i));
		}

		Count = 0;
		while (total % 2 == 0)
		{
			total /= 2;
			Count += 1;
		}
		printf("%d\n", Count);
	}
	return 0;
}