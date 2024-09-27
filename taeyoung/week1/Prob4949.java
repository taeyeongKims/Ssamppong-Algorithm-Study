package taeyoung.week1;

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Prob4949 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str;

        while(true) {
            Stack<String> stack = new Stack<>();
            str = br.readLine();
            if (str.equals(".")) {
                break;
            }

            StringTokenizer st = new StringTokenizer(str, "[]() ", true);
            while(st.hasMoreTokens()){
                String token = st.nextToken();
                if(token.equals("(") || token.equals("[")){
                    stack.push(token);
                } else if((token.equals(")") || token.equals("]")) && stack.empty()) {
                    stack.push(token);
                    break;
                }
                else if (token.equals(")")){
                    if(stack.peek().equals("(")){
                        stack.pop();
                    } else
                        break;
                } else if (token.equals("]")) {
                    if (stack.peek().equals("[")){
                        stack.pop();
                    } else
                        break;
                }
            }

            if(stack.empty())
                bw.write("yes\n");
            else
                bw.write("no\n");
        }

        bw.flush();
        bw.close();
    }
}