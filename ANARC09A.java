import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        ANARC09A solver = new ANARC09A();
        solver.solve(1, in, out);
        out.close();
    }

    static class ANARC09A {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testn = 1;
            while (true) {
                String s = in.next();
                if (s.charAt(0) == '-') {
                    break;
                }

                int a = 0;
                int ans = 0;
                for (int i = 0; i < s.length(); i++) {
                    if (s.charAt(i) == '}') {
                        if (a > 0) {
                            a--;
                            continue;
                        }
                        ans++;
                        a++;
                    } else {
                        a++;
                    }
                }
                ans += a / 2;
                out.println(testn + ". " + ans);
                testn++;
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

    }
}

