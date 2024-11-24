#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int res = 0;
vector<int> arr;

bool Solve(int index)
{
    int target = arr[index];
    int left = 0, right = N - 1;

    while (left < right)
    {

        if (left == index)
        {
            left++;
            continue;
        }
        if (right == index)
        {
            right--;
            continue;
        }

        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];


    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
        if (Solve(i))
            res++;

    cout << res << endl;
    return 0;
}
