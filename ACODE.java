import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        ACODE solver = new ACODE();
        solver.solve(1, in, out);
        out.close();
    }

    static class ACODE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String encrypted;
            while (!(encrypted = in.next()).equals("0")) {
                List<Integer> combo = new ArrayList<>(Collections.nCopies(encrypted.length() + 1, 0));
                combo.set(encrypted.length(), 1);
                for (int i = encrypted.length() - 1; i >= 0; i--) {
                    int comboForI = 0;
                    if (encrypted.charAt(i) == '0') {
                        continue;
                    }
                    for (int j = i; j < encrypted.length(); j++) {
                        BigDecimal num = new BigDecimal(encrypted.substring(i, j + 1));
                        if (num.compareTo(new BigDecimal(27)) == -1 && num.compareTo(new BigDecimal(0)) == 1) {
                            comboForI += combo.get(j + 1);
                        } else {
                            break;
                        }
                    }
                    combo.set(i, comboForI);
                }
                out.println(combo.get(0));
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

    }
}

