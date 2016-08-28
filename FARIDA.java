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
        FARIDA solver = new FARIDA();
        solver.solve(1, in, out);
        out.close();
    }

    static class FARIDA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                int n = in.nextInt();
                int[] arr = new int[n];
                for (int j = 0; j < n; j++) {
                    arr[j] = in.nextInt();
                }
                long next = 0;
                long nextnext = 0;
                for (int j = n - 1; j >= 0; j--) {
                    long ans = Math.max(arr[j] + nextnext, next);
                    nextnext = next;
                    next = ans;
                }
                int test = i + 1;
                out.println("Case " + test + ": " + next);
            }
            out.print(Integer.MAX_VALUE);
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

