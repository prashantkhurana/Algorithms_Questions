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
        GSS1 solver = new GSS1();
        solver.solve(1, in, out);
        out.close();
    }

    static class GSS1 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] originalArray = new int[n];
            for (int i = 0; i < n; i++) {
                originalArray[i] = in.nextInt();
            }
            SegmentTree segmentTree = new SegmentTree(originalArray);
            int m = in.nextInt();
            for (int i = 0; i < m; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                out.println(segmentTree.getMaxSubArray(x - 1, y));
            }
        }

    }

    static class SegmentTree {
        SegmentTree.SegmnetTreeNode[] segmentTree;
        int[] originalArray;

        public SegmentTree(int[] originalArray) {
            segmentTree = new SegmentTree.SegmnetTreeNode[originalArray.length * 4];
            this.originalArray = originalArray;
            buiildTree(0, originalArray.length, 1);
        }

        private void buiildTree(int start, int end, int index) {
            if (start == end - 1) {
                segmentTree[index] = new SegmentTree.SegmnetTreeNode();
                segmentTree[index].val = originalArray[start];
                segmentTree[index].sum = originalArray[start];
                segmentTree[index].max = originalArray[start];
                segmentTree[index].min = originalArray[start];
                segmentTree[index].maxPrefixSum = originalArray[start];
                segmentTree[index].maxPostFixSum = originalArray[start];
                segmentTree[index].maxSubArraySum = originalArray[start];
                return;
            }

            int mid = (start + end) / 2;
            buiildTree(start, mid, 2 * index);
            buiildTree(mid, end, 2 * index + 1);
            segmentTree[index] = new SegmentTree.SegmnetTreeNode();
            segmentTree[index].val = -1;
            segmentTree[index].max = Math.max(segmentTree[index * 2].max, segmentTree[index * 2 + 1].max);
            segmentTree[index].min = Math.min(segmentTree[index * 2].min, segmentTree[index * 2 + 1].min);
            segmentTree[index].sum = segmentTree[index * 2].sum + segmentTree[index * 2 + 1].sum;
            segmentTree[index].maxPrefixSum = Math.max(segmentTree[index * 2].maxPrefixSum, segmentTree[index * 2].sum + segmentTree[index * 2 + 1].maxPrefixSum);
            segmentTree[index].maxPostFixSum = Math.max(segmentTree[index * 2 + 1].maxPostFixSum, segmentTree[index * 2 + 1].sum + segmentTree[index * 2].maxPostFixSum);
            segmentTree[index].maxSubArraySum = Math.max(segmentTree[index * 2].maxSubArraySum, Math.max(segmentTree[index * 2 + 1].maxSubArraySum, segmentTree[2 * index].maxPostFixSum + segmentTree[2 * index + 1].maxPrefixSum));
        }

        public int getMaxSubArray(int x, int y) {
            return getMaxSubArray(0, originalArray.length, 1, x, y).maxSubArraySum;
        }

        private SegmentTree.SegmnetTreeNode getMaxSubArray(int start, int end, int index, int x, int y) {
            if (x <= start && y >= end) {
                return segmentTree[index];
            }

            if (x >= end || y <= start) {
                return null;
            }

            int mid = (start + end) / 2;
            SegmentTree.SegmnetTreeNode left = getMaxSubArray(start, mid, 2 * index, x, y);
            SegmentTree.SegmnetTreeNode right = getMaxSubArray(mid, end, 2 * index + 1, x, y);
            if (left == null) {
                return right;
            }
            if (right == null) {
                return left;
            }
            SegmentTree.SegmnetTreeNode segmnetTreeNode = new SegmentTree.SegmnetTreeNode();
            segmnetTreeNode.maxSubArraySum = Math.max(left.maxSubArraySum, Math.max(right.maxSubArraySum, left.maxPostFixSum + right.maxPrefixSum));
            segmnetTreeNode.maxPrefixSum = Math.max(left.maxPrefixSum, left.sum + right.maxPrefixSum);
            segmnetTreeNode.maxPostFixSum = Math.max(right.maxPostFixSum, right.sum + left.maxPostFixSum);
            segmnetTreeNode.sum = left.sum + right.sum;

            return segmnetTreeNode;
        }

        private static class SegmnetTreeNode {
            int max;
            int min;
            int sum;
            int maxPrefixSum;
            int maxPostFixSum;
            int val;
            int maxSubArraySum;

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

