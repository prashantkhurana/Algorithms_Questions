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
        CANTON solver = new CANTON();
        solver.solve(1, in, out);
        out.close();
    }

    static class CANTON {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                int n = in.nextInt();
                out.println("TERM " + n + " IS " + getNum(n));
            }
        }

        private String getNum(int n) {

            int sum = 0;
            int i = 1;
            while (sum < n) {
                sum += i;
                i++;
            }
            int diff = n - (sum - i) - 1;
            StringBuilder x = new StringBuilder();
            if (i % 2 == 0) {
                x.append(i - diff);
                x.append("/");
                x.append(diff);

            } else {
                x.append(diff);
                x.append("/");
                x.append(i - diff);
            }

            return x.toString();

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

