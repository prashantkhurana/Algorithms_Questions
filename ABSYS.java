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
        ABSYS solver = new ABSYS();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABSYS {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                String num1 = in.next();
                in.next();
                String num2 = in.next();
                in.next();
                String num3 = in.next();
                int diff;
                if (num1.contains("machula")) {
                    diff = Integer.parseInt(num3) - Integer.parseInt(num2);
                    out.println(diff + " + " + num2 + " = " + num3);
                }
                if (num2.contains("machula")) {
                    diff = Integer.parseInt(num3) - Integer.parseInt(num1);
                    out.println(num1 + " + " + diff + " = " + num3);
                }
                if (num3.contains("machula")) {
                    diff = Integer.parseInt(num1) + Integer.parseInt(num2);
                    out.println(num1 + " + " + num2 + " = " + diff);
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

