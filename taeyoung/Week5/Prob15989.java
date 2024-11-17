package taeyoung.Week5;

import java.io.*;

public class Prob15989 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[][] dp = new int[10001][4];
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(br.readLine());
        int num;
        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[2][2] = 1;
        dp[3][1] = 1;
        dp[3][2] = 1;
        dp[3][3] = 1;

        for(int i = 4; i<10001; i++){
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1] +dp[i-2][2];
            dp[i][3] = dp[i-3][1] +dp[i-3][2] +dp[i-3][3];
        }
        int result = 0;
        while(T-- > 0) {
            num = Integer.parseInt(br.readLine());
            result = dp[num][1] + dp[num][2] + dp[num][3];
            bw.write(result + "\n");
        }

        bw.flush();
        bw.close();
    }
}
