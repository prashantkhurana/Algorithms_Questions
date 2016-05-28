import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
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
        FENCE1 solver = new FENCE1();
        solver.solve(1, in, out);
        out.close();
    }

    static class FENCE1 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (true) {
                int length = in.nextInt();
                if (length == 0) {
                    break;
                }
                BigDecimal ans = ((BigDecimal.valueOf(length * length).divide(BigDecimal.valueOf(2))).divide(BigDecimal.valueOf(3.1415926), 10, BigDecimal.ROUND_HALF_UP));
                //.setScale(2);
                out.println(ans.setScale(2, BigDecimal.ROUND_HALF_UP));
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

