import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
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
        PERMUT2 solver = new PERMUT2();
        solver.solve(1, in, out);
        out.close();
    }

    static class PERMUT2 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int num;
            while ((num = in.nextInt()) != 0) {
                List<Integer> permutation = new ArrayList<>();
                for (int i = 0; i < num; i++) {
                    permutation.add(in.nextInt());
                }
                int i;
                for (i = 0; i < num; i++) {
                    if (permutation.get(i) > num || permutation.get(i) < 0 || permutation.get(permutation.get(i) - 1) != (i + 1)) {
                        break;
                    }
                }
                if (i < num) {
                    out.println("not ambiguous");
                } else {
                    out.println("ambiguous");
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

