package Week1;

import java.io.*;
import java.util.*;

public class Prob18427 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");

        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int h = Integer.parseInt(str[2]);
        int [][] dp = new int[n+1][h+1];

        List<Integer>[] list = new ArrayList[n+1];

        for(int i=1; i<=n; i++){
            list[i] = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()){
                list[i].add(Integer.parseInt(st.nextToken()));
            }
        }

        // 모든 사람이 아무 블럭도 선택하지 않을 경우의 수는 1개
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }

        for(int i=1; i<=n; i++){
            for(int height=1; height<=h; height++){
                for(Integer block: list[i]){
                    // i번째 사람이 가지고 있는 블럭이 현재 높이보다 작거나 같다면 사용, i-1번째 사람이 height - 블럭의 크기만큼 쌓은 횟수 더하기
                    if(height>=block){
                        dp[i][height] += dp[i-1][height-block];
                        dp[i][height] %=10007;
                    }
                }
                // i번째 사람은 블럭을 사용하지 않음
                dp[i][height] += dp[i-1][height];
                dp[i][height] %=10007;
            }
        }
        bw.write(String.valueOf(dp[n][h]));
        bw.flush();
        bw.close();
    }
}