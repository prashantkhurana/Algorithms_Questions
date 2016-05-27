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
        ARMY solver = new ARMY();
        solver.solve(1, in, out);
        out.close();
    }

    static class ARMY {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int testCount = in.nextInt();
            for (int i = 0; i < testCount; i++) {
                int NG = in.nextInt();
                int NM = in.nextInt();
                List<Integer> ngs = new ArrayList<>();
                List<Integer> nms = new ArrayList<>();

                for (int j = 0; j < NG; j++) {
                    ngs.add(in.nextInt());
                }
                for (int j = 0; j < NM; j++) {
                    nms.add(in.nextInt());
                }
                Collections.sort(ngs);
                Collections.sort(nms);

                int startg = 0, startm = 0;
                while (startg < ngs.size() && startm < nms.size()) {
                    int a = ngs.get(startg);
                    int b = nms.get(startm);
                    if (a > b) {
                        startm++;
                    } else if (b > a) {
                        startg++;
                    } else {
                        startm++;
                    }
                }
                if (startg == ngs.size()) {
                    out.println("MechaGodzilla");

                } else {
                    out.println("Godzilla");
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

