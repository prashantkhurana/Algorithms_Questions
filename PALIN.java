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
        PALIN solver = new PALIN();
        solver.solve(1, in, out);
        out.close();
    }

    static class PALIN {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                String num = in.next();
                out.println(nextPalindrome(new StringBuilder(num)));
            }
        }

        private String nextPalindrome(StringBuilder num) {
            int i = 0;
            int j = num.length() - 1;

            boolean inc = false;

            while (i < j) {
                if (num.charAt(i) > num.charAt(j)) {
                    inc = true;
                } else if (num.charAt(i) < num.charAt(j)) {
                    inc = false;
                }
                num.setCharAt(j, num.charAt(i));
                i++;
                j--;
            }
            if (!inc) {
                if (num.length() % 2 == 0) {
                    incrementAtI(num, num.length() / 2 - 1, num.length() / 2);
                } else {
                    incrementAtI(num, num.length() / 2, num.length() / 2);
                }
            }
            return num.toString();
        }

        private void incrementAtI(StringBuilder num, int i, int j) {
            incCharAt(num, i, j);
            while (i > 0 && num.charAt(i) == '0') {
                i--;
                j++;
                incCharAt(num, i, j);
            }
            if (num.charAt(i) == '0') {
                num.setCharAt(0, '1');
                num.append('1');
            }
            if (i != 0) {
                while (i >= 0) {
                    num.setCharAt(j, num.charAt(i));
                    i--;
                    j++;
                }
            }
        }

        private void incCharAt(StringBuilder num, int i, int j) {
            if (num.charAt(i) == '9') {
                num.setCharAt(i, '0');
            } else {
                num.setCharAt(i, (char) (num.charAt(i) + 1));
            }
            num.setCharAt(j, num.charAt(i));
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

