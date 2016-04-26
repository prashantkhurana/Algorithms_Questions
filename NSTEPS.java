import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
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
        NSTEPS solver = new NSTEPS();
        solver.solve(1, in, out);
        out.close();
    }

    static class NSTEPS {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCount = in.nextInt();
            for (int i = 0; i < testCount; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                if (x == y) {
                    if (x % 2 == 0) {
                        out.println(x + y);
                    } else {
                        out.println(x + y - 1);
                    }

                } else if (x == y + 2) {
                    if (x % 2 == 0) {
                        out.println(x + y);
                    } else {
                        out.println(x + y - 1);
                    }

                } else {
                    out.println("No Number");
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

