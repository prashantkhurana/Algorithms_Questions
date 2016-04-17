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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int tests = in.nextInt();
            for (int i = 0; i < tests; i++) {
                String a = in.next();
                String b = in.next();
                out.println(add(a, b));
            }
        }

        private String add(String a, String b) {

            int carry = 0;
            boolean cont_0 = true;
            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < Math.max(a.length(), b.length()); i++) {
                int x = 0;
                int y = 0;
                if (i < a.length()) {
                    x = Character.getNumericValue(a.charAt(i));
                }
                if (i < b.length()) {
                    y = Character.getNumericValue(b.charAt(i));
                }
                int currAns = x + y + carry;
                if (currAns > 9) {
                    carry = 1;
                    currAns = currAns % 10;
                } else {
                    carry = 0;
                }
                if (!(currAns == 0 && cont_0)) {
                    ans.append(currAns);
                    cont_0 = false;
                }
            }
            if (carry == 1) {
                ans.append(carry);
            }
            return ans.toString();

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

