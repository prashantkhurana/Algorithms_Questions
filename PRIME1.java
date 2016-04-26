import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        PRIME solver = new PRIME();
        solver.solve(1, in, out);
        out.close();
    }

    static class PRIME {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            List<Integer> primes = runSeiveAndGiveAllPrimes(40000);
            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                int start = in.nextInt();
                int end = in.nextInt();
                boolean[] isPrime = new boolean[end - start + 1];
                Arrays.fill(isPrime, true);
                double max = Math.ceil(Math.sqrt(end));
                for (int prime : primes) {
                    if (prime > max) {
                        break;
                    }
                    int lowestMul = (int) Math.ceil((double) start / prime);
                    markAsNonPrime(lowestMul, prime, isPrime, start, end);
                }
                for (int j = 0; j < isPrime.length; j++) {
                    if (isPrime[j] == true) {
                        int prime = j + start;
                        if (prime != 1) {
                            out.println(prime);
                        }
                    }
                }

            }
        }

        private void markAsNonPrime(int lowestMul, int prime, boolean[] isPrime, int start, int end) {
            if (lowestMul == 1) {
                lowestMul++;
            }
            int x = prime * lowestMul;
            while (x <= end) {
                isPrime[x - start] = false;
                lowestMul++;
                x = prime * lowestMul;
            }
        }

        private List<Integer> runSeiveAndGiveAllPrimes(int num) {
            boolean isPrime[] = new boolean[num];
            Arrays.fill(isPrime, Boolean.TRUE);
            ArrayList<Integer> primes = new ArrayList<>();

            for (int i = 2; i < isPrime.length; i++) {
                if (isPrime[i] == true) {
                    markAs(isPrime, i, Boolean.FALSE);
                    primes.add(i);
                }
            }
            return primes;
        }

        private void markAs(boolean[] isPrime, int i, Boolean aFalse) {
            int j = 2;
            int mul = i * j;
            while (mul < isPrime.length) {
                isPrime[mul] = aFalse;
                mul += i;
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

