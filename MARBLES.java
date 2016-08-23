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
        MARBLES solver = new MARBLES();
        solver.solve(1, in, out);
        out.close();
    }

    static class MARBLES {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            while (t > 0) {
                int n = in.nextInt();
                int k = in.nextInt();
                out.println(calc(n - 1, k - 1));
                t--;
            }

        }

        private long calc(int n, int k) {

            if (n == k) {
                return 1;
            }

            if ((n - k - k) > 0) {
                k = n - k;
            }

            long p = 1;
            int j = 1;
            for (int i = n; i > k; i--) {
                p = p * i / j;
                j++;
            }
            return p;
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

