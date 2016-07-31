import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
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
        BITMAP solver = new BITMAP();
        solver.solve(1, in, out);
        out.close();
    }

    static class BITMAP {
        int n;
        int m;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            while (t > 0) {
                n = in.nextInt();
                m = in.nextInt();
                int[][] visited = new int[183][183];
                int[][] arr = new int[183][183];
                Queue<Pair<Integer, Integer>> queue = new LinkedList<Pair<Integer, Integer>>();
                for (int i = 0; i < n; i++) {
                    String x = in.next();
                    for (int j = 0; j < m; j++) {
                        int temp = x.charAt(j) - '0';
                        if (temp == 0) {
                            arr[i][j] = 10000;
                        } else {
                            arr[i][j] = 0;
                            queue.add(Pair.of(i, j));
                            visited[i][j] = 1;
                        }
                    }
                }
                BFS(queue, arr, visited);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        out.print(arr[i][j] + " ");
                    }
                    out.println();
                }
                t--;
            }

        }

        private void BFS(Queue<Pair<Integer, Integer>> queue, int[][] arr, int[][] visited) {
            while (!queue.isEmpty()) {
                Pair<Integer, Integer> node = queue.remove();
                int i = node.getLeft();
                int j = node.getRight();
                if (i < n - 1 && visited[i + 1][j] == 0) {
                    arr[i + 1][j] = arr[i][j] + 1;
                    queue.add(Pair.of(i + 1, j));
                    visited[i + 1][j] = 1;
                }

                if (i > 0 && visited[i - 1][j] == 0) {
                    arr[i - 1][j] = arr[i][j] + 1;
                    queue.add(Pair.of(i - 1, j));
                    visited[i - 1][j] = 1;
                }

                if (j < m - 1 && visited[i][j + 1] == 0) {
                    arr[i][j + 1] = arr[i][j] + 1;
                    queue.add(Pair.of(i, j + 1));
                    visited[i][j + 1] = 1;
                }


                if (j > 0 && visited[i][j - 1] == 0) {
                    arr[i][j - 1] = arr[i][j] + 1;
                    queue.add(Pair.of(i, j - 1));
                    visited[i][j - 1] = 1;
                }
            }
        }

    }

    static class Pair<L, R> {
        private final L m_left;
        private final R m_right;

        public Pair(L left, R right) {
            this.m_left = left;
            this.m_right = right;
        }

        public static <L, R> Pair<L, R> of(L left, R right) {
            return new Pair(left, right);
        }

        public L getLeft() {
            return m_left;
        }

        public R getRight() {
            return m_right;
        }


        public int hashCode() {
            return m_left.hashCode() ^ m_right.hashCode();
        }


        public boolean equals(Object o) {
            if (o == null) {
                return false;
            }
            if (!(o instanceof Pair)) {
                return false;
            }
            Pair pairo = (Pair) o;
            return this.m_left.equals(pairo.getLeft()) &&
                    this.m_right.equals(pairo.getRight());
        }


        public String toString() {
            return "Pair{" +
                    "m_left=" + m_left +
                    ", m_right=" + m_right +
                    '}';
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

