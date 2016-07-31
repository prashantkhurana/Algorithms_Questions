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
        pp solver = new pp();
        solver.solve(1, in, out);
        out.close();
    }

    static class pp {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (true) {
                int budget = in.nextInt();
                int parties = in.nextInt();
                if (budget == 0 && parties == 0) {
                    break;
                }

                int[][] partiesWithBudget = new int[parties + 1][2];
                for (int i = 1; i <= parties; i++) {
                    int b = in.nextInt();
                    int f = in.nextInt();
                    partiesWithBudget[i][0] = b;
                    partiesWithBudget[i][1] = f;
                }
                int[][] fun = new int[budget + 1][parties + 1];
                int[][] bud = new int[budget + 1][parties + 1];

                for (int i = 0; i <= budget; i++) {
                    for (int j = 0; j <= parties; j++) {
                        if (i == 0 || j == 0) {
                            fun[i][j] = 0;
                            bud[i][j] = 0;
                            continue;
                        }

                        if (partiesWithBudget[j][0] > i) {
                            fun[i][j] = fun[i][j - 1];
                            bud[i][j] = bud[i][j - 1];
                            continue;
                        }

                        int y = i - partiesWithBudget[j][0];
                        fun[i][j] = Math.max(fun[i][j - 1], partiesWithBudget[j][1] + fun[i - partiesWithBudget[j][0]][j - 1]);
                        if (partiesWithBudget[j][1] + fun[i - partiesWithBudget[j][0]][j - 1] == fun[i][j - 1]) {
                            bud[i][j] = Math.min(bud[i][j - 1], partiesWithBudget[j][0] + bud[i - partiesWithBudget[j][0]][j - 1]);

                        } else if (fun[i][j] == fun[i][j - 1]) {
                            bud[i][j] = bud[i][j - 1];
                        } else {
                            bud[i][j] = partiesWithBudget[j][0] + bud[i - partiesWithBudget[j][0]][j - 1];
                        }
                    }
                }
                out.println(bud[budget][parties] + " " + fun[budget][parties]);
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

