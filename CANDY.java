import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
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
        CANDY solver = new CANDY();
        solver.solve(1, in, out);
        out.close();
    }

    static class CANDY {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int count = in.nextInt();
            while (count != -1) {
                int sum = 0;
                List<Integer> candies = new ArrayList<>();
                for (int i = 0; i < count; i++) {
                    int candies_count = in.nextInt();
                    candies.add(candies_count);
                    sum += candies_count;
                }
                if (sum % count == 0) {
                    int avg = sum / count;
                    int ans = 0;
                    for (Integer candies_count : candies) {
                        if (candies_count > avg) {
                            ans += (candies_count - avg);
                        }
                    }
                    out.println(ans);
                } else {
                    out.println("-1");
                }
                count = in.nextInt();
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
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

