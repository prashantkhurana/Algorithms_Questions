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
        STAMPS solver = new STAMPS();
        solver.solve(1, in, out);
        out.close();
    }

    static class STAMPS {
        public void solve(int testNumber, InputReader in, PrintWriter out) {

            int testCases = in.nextInt();
            for (int i = 0; i < testCases; i++) {
                int toBuy = in.nextInt();
                int numFriends = in.nextInt();
                List<Integer> candies = new ArrayList<>();
                for (int j = 0; j < numFriends; j++) {
                    candies.add(in.nextInt());
                }
                Collections.sort(candies, Collections.reverseOrder());
                int sum = 0;
                int x = 0;
                while (sum < toBuy && x < candies.size()) {
                    sum += candies.get(x);
                    x++;
                }
                int h = i + 1;
                out.println("Scenario #" + h + ":");
                if (sum >= toBuy) {
                    out.println(x);
                    out.println();
                } else {
                    out.println("impossible");
                    out.println();
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

