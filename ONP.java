import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        RPN solver = new RPN();
        solver.solve(1, in, out);
        out.close();
    }

    static class RPN {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCount = in.nextInt();
            for (int i = 0; i < testCount; i++) {
                String input = in.next();
                Stack<Character> stack = new Stack<>();
                StringBuilder ans = new StringBuilder();
                for (int j = 0; j < input.length(); j++) {
                    char x = input.charAt(j);
                    if (x >= 'a' && x <= 'z') {
                        ans.append(x);
                    } else if (x == '(') {
                        stack.push(x);
                    } else if (x == ')') {
                        while (stack.peek() != '(') {
                            ans.append(stack.peek());
                            stack.pop();
                        }
                        stack.pop();
                    } else {
                        stack.push(x);
                    }
                }
                out.println(ans);
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

