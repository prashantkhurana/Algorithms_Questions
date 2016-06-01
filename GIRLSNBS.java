import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.RoundingMode;
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
        GIRLSNBS solver = new GIRLSNBS();
        solver.solve(1, in, out);
        out.close();
    }

    static class GIRLSNBS {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int boys, girls;
            while (((girls = in.nextInt()) != -1) && ((boys = in.nextInt()) != -1)) {
                BigDecimal large;
                BigDecimal small;
                if (girls >= boys) {
                    large = BigDecimal.valueOf(girls);
                    small = BigDecimal.valueOf(boys);
                } else {
                    large = BigDecimal.valueOf(boys);
                    small = BigDecimal.valueOf(girls);
                }
                small = small.add(BigDecimal.ONE);
                BigDecimal ans = large.divide(small, RoundingMode.UP);
                out.println(ans);
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

