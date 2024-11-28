package taeyoung.Week7;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Prob2785 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < num; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(list);

        int rst = 0;
        while(list.size() > 1){
            list.set(0, list.get(0)-1);
            list.remove(list.size()-1);

            if(list.get(0) == 0)
                list.remove(0);

            rst++;
        }

        bw.write(rst + "\n");
        bw.flush();
        bw.close();
    }
}
