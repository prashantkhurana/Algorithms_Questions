import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        HANGOVER solver = new HANGOVER();
        solver.solve(1, in, out);
        out.close();
    }

    static class HANGOVER {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            BigDecimal sum = new BigDecimal(0);
            sum.setScale(2);
            List<BigDecimal> cToLength = new ArrayList<>();
            for (int i = 2; i < 300; i++) {
                sum = sum.add(new BigDecimal(1.00 / i));
                cToLength.add(sum);
            }
            BigDecimal zero = new BigDecimal(0);
            while (true) {
                BigDecimal c = new BigDecimal(in.next());
                if (c.compareTo(zero) == 0) {
                    break;
                }
                int ans = Collections.binarySearch(cToLength, c);
                if (ans >= 0) {
                    out.println(ans + 1 + " card(s)");
                } else {
                    out.println(-ans + " card(s)");
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

    }
}

