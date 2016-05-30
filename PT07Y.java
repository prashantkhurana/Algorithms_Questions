import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        PT07Y solver = new PT07Y();
        solver.solve(1, in, out);
        out.close();
    }

    static class PT07Y {
        List<Integer>[] graph = new ArrayList[10003];
        boolean[] visited = new boolean[10003];
        int nodes;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            nodes = in.nextInt();
            for (int i = 0; i <= nodes; i++) {
                graph[i] = new ArrayList<>();
            }
            int edges = in.nextInt();
            for (int i = 0; i < edges; i++) {
                int start = in.nextInt();
                int end = in.nextInt();
                graph[start].add(end);
                graph[end].add(start);
            }
            dfs(1);
            if (isTree() && edges == nodes - 1) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }

        private void dfs(int start) {
            visited[start] = true;
            for (int node : graph[start]) {
                if (visited[node]) {
                    continue;
                } else {
                    dfs(node);
                }
            }
        }

        private boolean isTree() {
            for (int i = 1; i <= nodes; i++) {
                if (!visited[i]) {
                    return false;
                }
            }
            return true;
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

