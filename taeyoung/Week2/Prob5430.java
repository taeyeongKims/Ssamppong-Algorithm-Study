package taeyoung.Week2;

import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Prob5430 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {


        ArrayDeque<Integer> deque = new ArrayDeque<>();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            String command = br.readLine();
            int n = Integer.parseInt(br.readLine());

            st = new StringTokenizer(br.readLine(), "[],");

            for(int i = 0; i < n; i++){
                deque.add(Integer.parseInt(st.nextToken()));
            }

            func(command, deque);
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();

    }
    public static void func(String command, ArrayDeque<Integer> deque){
        boolean isRight = true;

        for(char cmd : command.toCharArray()){
            if (cmd == 'R'){
                isRight = !isRight;
                continue;
            }

            if(isRight){
                if(deque.pollFirst() == null){
                    sb.append("error\n");
                    return;
                }
            }
            else {
                if(deque.pollLast() == null){
                    sb.append("error\n");
                    return;
                }
            }
        }

        sb.append('[');

        if(deque.size() > 0){
            if (isRight) {
                sb.append(deque.pollFirst());

                while (!deque.isEmpty()) {
                    sb.append(',').append(deque.pollFirst());
                }
            }
            else {
                sb.append(deque.pollLast());

                while(!deque.isEmpty()){
                    sb.append(',').append(deque.pollLast());
                }
            }
        }

        sb.append(']').append('\n');
    }
}
