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
        AIBOHP solver = new AIBOHP();
        solver.solve(1, in, out);
        out.close();
    }

    static class AIBOHP {
        int[][] ans = new int[2][6002];
        private String s;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();

            for (int i = 0; i < t; i++) {
                s = in.next();
                for (int j = 0; j < s.length(); j++) {
                    ans[0][j] = 0;
                    ans[1][j] = 0;
                }
                out.println(getAns(s));
            }
        }

        private int getAns(String s) {

            for (int i = 1; i < s.length(); i++) {
                int[] ans2 = new int[s.length()];
                for (int j = 0; j < s.length() - i; j++) {
                    char start = s.charAt(j);
                    char end = s.charAt(i + j);
                    if (start == end) {
                        ans2[j] = ans[0][j + 1];
                    } else {
                        ans2[j] = 1 + Math.min(ans[1][j], ans[1][j + 1]);
                    }
                }
                for (int j = 0; j < s.length(); j++) {
                    ans[0][j] = ans[1][j];
                    ans[1][j] = ans2[j];
                }
            }
            return ans[1][0];
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

