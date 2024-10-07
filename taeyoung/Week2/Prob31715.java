package taeyoung.Week2;

import java.io.*;
import java.util.*;

public class Prob31715 {
    static int N, M, D;
    static int[][] info;
    static final int MOD = 1_000_000_007;
    static long rst;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        D = Integer.parseInt(input[2]);

        info = new int[N][M];

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                info[i][j] = Integer.parseInt(input[j]) + D * (i + 1);
            }
            Arrays.sort(info[i]); // 각 행을 정렬
        }

        rst = Fact(M);

        for (int row = 1; row < N; ++row) {
            long poss = 1;

            for (int col = 0; col < M; ++col) {
                int cnt = 0;

                // cnt 계산: 이전 행과 비교하여 현재 값이 더 큰 경우 cnt 증가
                for (int j = 0; j < M; ++j) {
                    if (info[row][col] > info[row - 1][j]) {
                        cnt++;
                    }
                }

                poss = (poss * (cnt - col)) % MOD;
            }

            if (poss <= 0) {
                rst = 0;
                break;
            }

            rst = (rst * poss) % MOD;
        }

        System.out.println(rst);
    }

    static long Fact(int inNum) {
        long R = 1;
        for (int i = 1; i <= inNum; i++) {
            R = (R * i) % MOD;
        }
        return R;
    }
}
