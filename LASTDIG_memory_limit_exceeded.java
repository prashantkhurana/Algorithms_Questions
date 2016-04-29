import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
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
        LASTDIG solver = new LASTDIG();
        solver.solve(1, in, out);
        out.close();
    }

    static class LASTDIG {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                int ans = 1;
                int curr = a % 10;
                while (b != 0) {
                    if ((b % 2) == 1) {
                        ans = (ans * curr) % 10;
                    }
                    curr = (curr * curr) % 10;
                    b = b / 2;
                }
                if (a != 0) {
                    out.println(ans);
                } else {
                    out.println(0);
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

