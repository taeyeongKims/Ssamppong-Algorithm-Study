#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
using int64 = long long int;
vector<int64> vec;
vector<int64> segTree;

int64 InitTree(int node, int start, int end)
{
    if (start == end)
    {
        return segTree[node] = vec[start];
    }
    else
    {
        int mid = (start + end) / 2;
        int64 leftSum = InitTree(node * 2, start, mid);
        int64 rightSum = InitTree(node * 2 + 1, mid + 1, end);
        return segTree[node] = leftSum + rightSum;
    }
}

void UpdateTree(int node, int start, int end, int idx, int64 diff)
{
    if (idx < start || idx > end) return;
    segTree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        UpdateTree(node * 2, start, mid, idx, diff);
        UpdateTree(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int64 Query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return segTree[node];
    int mid = (start + end) / 2;
    return Query(node * 2, start, mid, left, right) + Query(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    vec.resize(N);
    segTree.resize(N * 4);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    InitTree(1, 0, N - 1);

    for (int i = 0; i < M + K; i++)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            int idx;
            int64 val;
            cin >> idx >> val;
            idx--;
            int64 diff = val - vec[idx];
            vec[idx] = val;
            UpdateTree(1, 0, N - 1, idx, diff);
        }
        else if (cmd == 2)
        {
            int left, right;
            cin >> left >> right;
            left--; right--;
            cout << Query(1, 0, N - 1, left, right) << '\n';
        }
    }

    return 0;
}
