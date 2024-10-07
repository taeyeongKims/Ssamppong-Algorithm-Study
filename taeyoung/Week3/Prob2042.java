package taeyoung.Week3;


import java.io.*;
import java.util.StringTokenizer;

public class Prob2042 {
    static long[] arr, tree;
    static long rst = 0;
    static int N, M, K;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new long[N+1];
        for(int i=1; i<=N; i++){
            arr[i] = Long.parseLong(br.readLine());
        }

        int k = (int)Math.ceil(Math.log(N) / Math.log(2)) + 1;
        int treeSize = (int)Math.pow(2, k);

        tree = new long[treeSize];
        init(1, N, 1);

        while(K-- > 0){
            while(true){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                long c = Long.parseLong(st.nextToken());

                if(a == 1){
                    long dir = c - arr[b];
                    arr[b] = c;
                    update(1, N, 1, b, dir);
                }
                if(a == 2){
                    rst = sum(1, N, 1, b, (int)c);
                    break;
                }
            }
            bw.write(String.valueOf(rst) + "\n"); // 결과 출력
        }
        bw.flush();
        bw.close();
    }

    static long init(int start, int end, int node){
        if(start == end){
            return tree[node] = arr[start];
        }

        int mid = (start + end) / 2;

        return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }

    static void update(int start, int end, int node, int idx, long dir){
        if(idx < start || idx > end){
            return;
        }

        tree[node] += dir;

        if (start == end)
            return;

        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, dir);
        update(mid + 1, end, node * 2 + 1, idx, dir);
    }

    static long sum(int start, int end, int node, int left, int right){
        if(left > end || right < start){
            return 0;
        }

        if (left <= start && right >= end) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
    }

}