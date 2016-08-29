import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        PIGBANK solver = new PIGBANK();
        solver.solve(1, in, out);
        out.close();
    }

    static class PIGBANK {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                int e = in.nextInt();
                int f = in.nextInt();
                int w = f - e;
                int n = in.nextInt();
                int[] value = new int[n];
                int[] weight = new int[n];
                for (int j = 0; j < n; j++) {
                    value[j] = in.nextInt();
                    weight[j] = in.nextInt();
                }
                long[] ans = new long[w + 1];
                Arrays.fill(ans, 500000044);
                ans[0] = 0;
                for (int j = 1; j <= w; j++) {
                    for (int k = 0; k < n; k++) {
                        if (weight[k] <= j) {
                            ans[j] = Math.min(ans[j], value[k] + ans[j - weight[k]]);
                        }
                    }
                }
                if (ans[w] != 500000044) {
                    out.println("The minimum amount of money in the piggy-bank is " + ans[w] + ".");
                } else {
                    out.println("This is impossible.");
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

