package taeyoung.Week4;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Prob1976 {

    static int[] parent;
    static int N, M;
    static List<Integer> trip;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 1; i <= N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 1; j <= N; j++) {
                if (Integer.parseInt(input[j - 1]) == 1) {
                    union(i, j);
                }
            }
        }

        trip = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        boolean possible = true;
        int root = find(trip.get(0));
        for (int i = 1; i < M; i++) {
            if (find(trip.get(i)) != root) {
                possible = false;
                break;
            }
        }

        bw.write(possible ? "YES\n" : "NO\n");
        bw.flush();
        bw.close();
    }

    static int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }
}
