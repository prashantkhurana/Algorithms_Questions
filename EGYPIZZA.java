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
        EGYPIZZA solver = new EGYPIZZA();
        solver.solve(1, in, out);
        out.close();
    }

    static class EGYPIZZA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Map<String, Integer> count = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String x = in.next();
                if (count.containsKey(x)) {
                    int c = count.get(x);
                    count.put(x, c + 1);
                } else {
                    count.put(x, 1);
                }
            }

            int ans = 0;
            int one = 0;
            int three = 0;
            int half = 0;
            if (count.containsKey("1/4")) {
                one = count.get("1/4");
            }
            if (count.containsKey("3/4")) {
                three = count.get("3/4");
            }
            if (count.containsKey("1/2")) {
                half = count.get("1/2");
            }
            ans += three;
            one -= three;

            ans += half / 2;

            if (half % 2 != 0) {
                ans += 1;
                one -= 2;
            }

            if (one > 0) {
                ans += one / 4;
                if (one % 4 > 0) {
                    ans++;
                }
            }
            ans++;
            out.print(ans);
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

