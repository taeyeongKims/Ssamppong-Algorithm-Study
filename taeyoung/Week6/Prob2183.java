package taeyoung.Week6

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Prob2183 {
    static int[] status, result;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int bulb = Integer.parseInt(br.readLine());
        status = new int[bulb];
        result = new int[bulb];

        String[] split = br.readLine().split("");
        for (int i = 0; i < bulb; i++) {
            status[i] = Integer.parseInt(split[i]);
        }

        split = br.readLine().split("");
        for (int i = 0; i < bulb; i++) {
            result[i] = Integer.parseInt(split[i]);
        }

        int[] switchOn = Arrays.copyOf(status, bulb);
        int[] switchOff = Arrays.copyOf(status, bulb);
        int countOn = 1;
        int countOff = 0;
        boolean flagOn = false;
        boolean flagOff = false;
        turnOn(switchOn, 0);

        for(int i = 1; i < bulb; i++){
            if(switchOn[i-1] != result[i-1]){
                turnOn(switchOn, i);
                countOn++;
            }

            if(Arrays.equals(switchOn, result)){
                flagOn = true;
                break;
            }
        }

        for (int i = 1; i < bulb; i++) {
            if(switchOff[i-1] != result[i-1]){
                turnOn(switchOff, i);
                countOff++;
            }

            if(Arrays.equals(switchOff, result)){
                flagOff = true;
                break;
            }
        }

        int rst;
        if(flagOn && flagOff)
            rst = Math.min(countOn, countOff);
        else if(flagOn)
            rst = countOn;
        else if(flagOff)
            rst = countOff;
        else
            rst = -1;


        bw.write(rst+"\n");
        bw.flush();
        bw.close();

    }
    static void turnOn(int[] arr, int index){
        if(index-1 >= 0)
            arr[index-1] = 1-arr[index-1];

        arr[index] = 1-arr[index];

        if(index + 1 < arr.length)
            arr[index+1] = 1-arr[index+1];
    }
}
