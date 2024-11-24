package taeyoung.Week6

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Prob1253 {
    static int num, left, right;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        num = Integer.parseInt(br.readLine());
        arr = new int[num];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        left = 0;
        right = num-1;
        int rst = solution();
        bw.write(rst + "\n");
        bw.flush();
        bw.close();
    }

    static int solution(){
        int cnt = 0;

        for (int i = 0; i < num; i++) {
            left = 0;
            right = num-1;
            while(left < right){
                if(left == i){
                    left++;
                }
                else if(right == i){
                    right--;
                }
                else if(arr[left] + arr[right] > arr[i]){
                    right--;
                }
                else if(arr[left] + arr[right] < arr[i]){
                    left++;
                }
                else{
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
}
