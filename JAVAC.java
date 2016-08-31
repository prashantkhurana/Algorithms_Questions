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
        JAVAC solver = new JAVAC();
        solver.solve(1, in, out);
        out.close();
    }

    static class JAVAC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = "";
            try {
                while (true) {
                    s = in.next();
                    if (s.isEmpty()) {
                        break;
                    }
                    if (s.contains("_")) {
                        convertToJava(s, out);
                    } else {
                        convertToC(s, out);
                    }

                }
            } catch (Exception e) {
                out.println("Exception in input " + s + "   " + e);

            }
        }

        private void convertToC(String s, PrintWriter out) {
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '_') {
                    out.println("Error!");
                    return;
                }
                if (Character.isUpperCase(s.charAt(i))) {
                    if (i == 0) {
                        out.println("Error!");
                        return;
                    }
                    stringBuilder.append('_');
                    stringBuilder.append(Character.toLowerCase(s.charAt(i)));
                    continue;
                }
                stringBuilder.append(s.charAt(i));
            }
            out.println(stringBuilder.toString());

        }

        private void convertToJava(String s, PrintWriter out) {
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                if (Character.isUpperCase(s.charAt(i))) {
                    out.println("Error!");
                    return;
                }
                if (s.charAt(i) == '_') {
                    if (i == 0 || s.length() == i + 1 || s.charAt(i + 1) == '_' || Character.isUpperCase(s.charAt(i +
                            1))) {
                        out.println("Error!");
                        return;
                    }
                    stringBuilder.append(Character.toUpperCase(s.charAt(i + 1)));
                    i++;
                    continue;
                }
                stringBuilder.append(s.charAt(i));
            }
            out.println(stringBuilder.toString());
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

