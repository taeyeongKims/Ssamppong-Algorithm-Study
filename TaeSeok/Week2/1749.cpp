#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  

using namespace std;

int kadane(const vector<int>& arr) {
    int cur_max = arr[0];
    int total_max = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) 
    {
        cur_max = max(arr[i], cur_max + arr[i]);
        total_max = max(total_max, cur_max);
    }

    return total_max;
}



int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    int rows = arr.size();
    int cols = arr[0].size();
    int max_sum = INT_MIN;

    for (int start_row = 0; start_row < rows; ++start_row)
    {
        vector<int> temp(cols, 0);

        for (int end_row = start_row; end_row < rows; ++end_row)
        {

            for (int col = 0; col < cols; ++col)
                temp[col] += arr[end_row][col];

            int cur_max_sum = kadane(temp);

            max_sum = max(max_sum, cur_max_sum);
        }
    }
    cout << max_sum;

    return 0;
}
