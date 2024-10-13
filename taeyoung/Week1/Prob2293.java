package taeyoung.Week1;

import java.io.*;

public class Prob2293 {
    static int kind = 0;
    static int goal = 0;
    static int[] coin;
    static int[] dp = new int[10001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");
        kind = Integer.parseInt(str[0]);
        goal = Integer.parseInt(str[1]);
        coin = new int[kind];
        for(int i =0; i<kind; i++){
            coin[i] = Integer.parseInt(br.readLine());
        }

        dp[0] = 1;

        for(int i = 0 ; i < kind; i++) {
            for (int j = coin[i]; j <= goal; j++)
                dp[j] += dp[j - coin[i]];
        }


        bw.write(String.valueOf(dp[goal]));
        bw.flush();
        bw.close();
    }
}