package taeyoung.week1;

import java.io.*;

public class Prob2048 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int level = Integer.parseInt(br.readLine());

        for(int i=0; i<level; i++){
            int count = 0;
            sb.delete(0, sb.length());
            String[] num = br.readLine().split(" ");
            int l = Integer.parseInt(num[0]);
            int r = Integer.parseInt(num[1]);

            if(r>=4) {
                bw.write(r+"\n");
                continue;
            }
            for(int k = l; k<=r; k++){
                Long add = Long.parseUnsignedLong("1" + "0".repeat(k), 2);
                sb.append(add);
            }

            String result = sb.toString();
            long longResult = Long.parseUnsignedLong(result);
            result = Long.toBinaryString(longResult);



            for(int k = result.length()-1; k>=0; k--){
                if(result.charAt(k) == '0')
                    count++;
                else
                    break;
            }
            bw.write(count+"\n");
        }
        bw.flush();
        bw.close();
    }
}
