import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
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
        COINS solver = new COINS();
        solver.solve(1, in, out);
        out.close();
    }

    static class COINS {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            Map<Integer, Long> max = new HashMap<>();
            max.put(0, 0L);
            String z;
            while (!(z = in.next()).isEmpty()) {
                int number = Integer.parseInt(z);
                out.println(compute(max, number));
            }
        }

        private Long compute(Map<Integer, Long> max, int number) {

            if (max.containsKey(number)) {
                return max.get(number);
            }
            max.put(number, Math.max(number, compute(max, number / 2) + compute(max, number / 3) + compute(max, number / 4)));
            return max.get(number);
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

