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
        INVCNT solver = new INVCNT();
        solver.solve(1, in, out);
        out.close();
    }

    static class INVCNT {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                int n = in.nextInt();
                int[] arr = new int[n + 1];
                int max = 0;
                for (int i1 = 1; i1 <= n; i1++) {
                    arr[i1] = in.nextInt();
                    max = Math.max(max, arr[i1]);
                }
                BIT bit = new BIT(max);
                long inv = 0;
                for (int j = n; j > 0; j--) {
                    inv += bit.read(arr[j] - 1);
                    bit.update(arr[j], 1);
                }
                out.println(inv);
            }
        }

    }

    static class BIT {
        int size;
        int[] freq;

        public BIT(int size) {
            this.size = size;
            freq = new int[size + 1];
        }

        public void update(int index, int value) {
            while (index <= size) {
                freq[index] += value;
                index += (index & -index);
            }
        }

        public int read(int index) {
            int sum = 0;
            while (index >= 1) {
                sum += freq[index];
                index -= (index & -index);
            }
            return sum;
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

