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
        TRT solver = new TRT();
        solver.solve(1, in, out);
        out.close();
    }

    static class TRT {
        int[] treats = new int[2100];
        int[][] ans = new int[2100][2100];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            for (int i = 1; i <= n; i++) {
                treats[i] = in.nextInt();
            }
            out.println(getAns(1, n, 1));
        }

        private int getAns(int start, int end, int day) {
            if (start > end) {
                return 0;
            }
            if (ans[start][end] != 0) {
                return ans[start][end];
            }
            ans[start][end - 1] = getAns(start, end - 1, day + 1);
            ans[start + 1][end] = getAns(start + 1, end, day + 1);
            ans[start][end] = Math.max(day * treats[end] + ans[start][end - 1], day * treats[start] + ans[start + 1][end]);
            return ans[start][end];
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

