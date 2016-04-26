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
        TOANDFRO solver = new TOANDFRO();
        solver.solve(1, in, out);
        out.close();
    }

    static class TOANDFRO {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int columns = in.nextInt();
            while (columns != 0) {
                String encryptedText = in.next();
                int start = 2 * columns - 1;
                for (int i = 0; i < columns; i++) {
                    int j = i;
                    boolean odd = true;
                    while (j < encryptedText.length()) {
                        out.print(encryptedText.charAt(j));
                        if (odd) {
                            j = j + start;
                        } else {
                            j = j + (2 * columns - start);
                        }
                        odd = !odd;
                    }
                    start -= 2;
                }
                columns = in.nextInt();
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

