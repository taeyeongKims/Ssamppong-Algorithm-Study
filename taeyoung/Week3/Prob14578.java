package taeyoung.Week3;

import java.io.*;

public class Prob14578 {
    static int[] dp;
    static final int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 0;

        long rst = (Fact(n) * Solution(n)) % MOD;

        bw.write(String.valueOf(rst));
        bw.flush();
        bw.close();
    }
    static long Fact(int n){
        int rst = 1;
        for(int i = 2; i<=n; i++){
            rst = (rst * i) % MOD;
        }
        return rst;
    }
    static int Solution(int num) {

        if (num == 0) {
            return dp[0];
        }

        if (num == 1) {
            return dp[1];
        }

        for (int i = 2; i <= num; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }
        return dp[num] % MOD;
    }
}
