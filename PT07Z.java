import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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
        PT07Z solver = new PT07Z();
        solver.solve(1, in, out);
        out.close();
    }

    static class PT07Z {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int nodes = in.nextInt();
            List<Integer>[] graph = new ArrayList[nodes + 1];
            for (int i = 0; i < graph.length; i++) {
                graph[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < nodes - 1; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                graph[a].add(b);
                graph[b].add(a);
            }
            Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
            queue.add(new Pair<Integer, Integer>(1, 0));
            boolean[] visited = new boolean[nodes + 1];
            Pair<Integer, Integer> farthest = BFS(queue, visited, graph);
            visited = new boolean[nodes + 1];
            queue.add(new Pair<Integer, Integer>(farthest.getLeft(), 0));
            Pair<Integer, Integer> farthest2 = BFS(queue, visited, graph);
            out.println(farthest2.getRight());
        }

        private Pair<Integer, Integer> BFS(Queue<Pair<Integer, Integer>> queue, boolean[] visited, List<Integer>[] graph) {
            while (!queue.isEmpty()) {
                Pair<Integer, Integer> first = queue.poll();
                visited[first.getLeft()] = true;
                for (int node : graph[first.getLeft()]) {
                    if (!visited[node]) {
                        queue.add(new Pair<Integer, Integer>(node, first.getRight() + 1));
                    }
                }
//            for (int i =0; i < graph[first.getLeft()].size(); i++)  {
//                if (!visited[graph[first.getLeft()].get(i)]) {
//                    queue.add(new Pair<Integer, Integer>(graph[first.getLeft()].get(i), first.getRight()+1));
//                }
//            }
                if (queue.isEmpty()) {
                    return first;
                }
            }
            return null;
        }

    }

    static class Pair<L, R> {
        private final L left;
        private final R right;

        public Pair(L left, R right) {
            this.left = left;
            this.right = right;
        }

        public L getLeft() {
            return left;
        }

        public R getRight() {
            return right;
        }


        public int hashCode() {
            return left.hashCode() ^ right.hashCode();
        }


        public boolean equals(Object o) {
            if (!(o instanceof Pair)) return false;
            Pair pairo = (Pair) o;
            return this.left.equals(pairo.getLeft()) &&
                    this.right.equals(pairo.getRight());
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

