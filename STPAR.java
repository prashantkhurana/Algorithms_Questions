import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Vector;
import java.util.StringTokenizer;
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
        STPAR solver = new STPAR();
        solver.solve(1, in, out);
        out.close();
    }

    static class STPAR {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n;
            while (((n = in.nextInt()) != 0)) {
                int lookingFor = 1;
                Stack<Integer> stack = new Stack<>();
                for (int i = 0; i < n; i++) {
                    int t = in.nextInt();
                    boolean used = false;
                    while (true) {
                        if (t == lookingFor) {
                            lookingFor++;
                            used = true;
                        }
                        if (!stack.isEmpty() && lookingFor == stack.peek()) {
                            lookingFor++;
                            stack.pop();
                        } else {
                            break;
                        }
                    }
                    if (!used) {
                        stack.push(t);
                    }
                }

                if (lookingFor == n + 1) {
                    out.println("yes");
                } else {
                    out.println("no");
                }
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
                } catch (Exception e) {
                    return "";
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

