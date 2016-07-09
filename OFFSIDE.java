import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        OFFSIDE solver = new OFFSIDE();
        solver.solve(1, in, out);
        out.close();
    }

    static class OFFSIDE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a = in.nextInt();
            int d = in.nextInt();
            List<Integer> attackers = new ArrayList<>();
            List<Integer> defenders = new ArrayList<>();
            while (a != 0 && d != 0) {
                for (int i = 0; i < a; i++) {
                    attackers.add(in.nextInt());
                }
                for (int i = 0; i < d; i++) {
                    defenders.add(in.nextInt());
                }
                int closestAttacker = Collections.min(attackers);
                int defender2nd = findSecondLowest(defenders);
                if (closestAttacker < defender2nd) {
                    out.println("Y");
                } else {
                    out.println("N");
                }
                a = in.nextInt();
                d = in.nextInt();
                attackers.clear();
                defenders.clear();
            }


        }

        private int findSecondLowest(List<Integer> defenders) {
            if (defenders.size() == 1) {
                return defenders.get(0);
            } else {
                Integer min;
                Integer min2;
                if (defenders.get(0) < defenders.get(1)) {
                    min = defenders.get(0);
                    min2 = defenders.get(1);
                } else {
                    min = defenders.get(1);
                    min2 = defenders.get(0);
                }
                for (int i = 2; i < defenders.size(); i++) {
                    int current = defenders.get(i);
                    if (current < min) {
                        min2 = min;
                        min = current;
                    } else if (current < min2) {
                        min2 = current;
                    }
                }
                return min2;
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

