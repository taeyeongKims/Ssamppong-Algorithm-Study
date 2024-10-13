#include <iostream>
#include <vector>
using namespace std;

class SegmentTree 
{
public:
    // 세그먼트 트리 생성
    void build(vector<long long>& arr, int node, int start, int end) 
    {
        if (start == end) 
            tree[node] = arr[start];
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    // 구간 합 쿼리
    long long query(int node, int start, int end, int L, int R) 
    {
        if (R < start || end < L)
            return 0;  // 범위 밖
        if (L <= start && end <= R) 
            return tree[node];  

        int mid = (start + end) / 2;
        long long left_sum = query(2 * node, start, mid, L, R);
        long long right_sum = query(2 * node + 1, mid + 1, end, L, R);
        return left_sum + right_sum;
    }

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) 
            tree[node] = val;
        else 
        {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) 
                update(2 * node, start, mid, idx, val);
            else 
                update(2 * node + 1, mid + 1, end, idx, val);

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    SegmentTree(vector<long long>& arr) 
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    long long query(int L, int R) 
    {
        return query(1, 0, n - 1, L, R);
    }

    void update(int idx, long long val) 
    {
        update(1, 0, n - 1, idx, val);
    }

public:
    vector<long long> tree;
    int n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    SegmentTree segTree(arr);

    for (int i = 0; i < M + K; i++) 
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) 
            segTree.update(b - 1, c);
        else if (a == 2) 
            cout << segTree.query(b - 1, c - 1) << "\n";
        
    }

    return 0;
}
