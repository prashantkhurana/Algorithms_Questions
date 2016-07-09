import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;
import java.util.Map;
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
        NY10A solver = new NY10A();
        solver.solve(1, in, out);
        out.close();
    }

    static class NY10A {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                int d = in.nextInt();
                Map<String, Integer> count = new LinkedHashMap<>();
                count.put("TTT", 0);
                count.put("TTH", 0);
                count.put("THT", 0);
                count.put("THH", 0);
                count.put("HTT", 0);
                count.put("HTH", 0);
                count.put("HHT", 0);
                count.put("HHH", 0);

                String tossed = in.next();
                for (int j = 0; j < 38; j++) {
                    StringBuilder stringBuilder = new StringBuilder();
                    stringBuilder.append(tossed.charAt(j));
                    stringBuilder.append(tossed.charAt(j + 1));
                    stringBuilder.append(tossed.charAt(j + 2));
                    count.put(stringBuilder.toString(), count.get(stringBuilder.toString()) + 1);
                }
                out.print(i + 1);
                out.print(" ");
                for (int j : count.values()) {
                    out.print(j + " ");
                }
                out.println();
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

