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

	// �������� ���� ��ġ ��, �Ķ����� ���� �������� 
}