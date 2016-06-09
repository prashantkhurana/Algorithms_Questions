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
        EDIST solver = new EDIST();
        solver.solve(1, in, out);
        out.close();
    }

    static class EDIST {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                String s1 = in.next();
                String s2 = in.next();
                int[][] dp = new int[2003][2003];
                for (int i1 = 0; i1 <= s1.length(); i1++) {
                    dp[0][i1] = i1;
                    dp[i1][0] = i1;
                }


                for (int i1 = 1; i1 <= s1.length(); i1++) {
                    for (int j1 = 1; j1 <= s2.length(); j1++) {
                        if (s1.charAt(i1 - 1) == s2.charAt(j1 - 1)) {
                            dp[i1][j1] = dp[i1 - 1][j1 - 1];
                        } else {
                            dp[i1][j1] = 1 + Math.min(dp[i1 - 1][j1 - 1], Math.min(dp[i1][j1 - 1], dp[i1 - 1][j1]));
                        }
                    }
                }
                out.println(dp[s1.length()][s2.length()]);

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

