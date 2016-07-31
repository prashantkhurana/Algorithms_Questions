package test4;
import static java.lang.Math.max;
import static java.lang.Math.min;

/**
 * Created by PKhurana on 7/30/16.
 */
public class SegmentTree {


    private static class SegmentTreeNode {
        int max;
        int min;
        int sum;
        int maxPrefixSum;
        int maxPostFixSum;
        int val;
        int maxSubArraySum;
    }

    SegmentTreeNode[] segmentTree;
    int[] originalArray;

    public SegmentTree(int[] originalArray) {
        segmentTree = new SegmentTreeNode[originalArray.length*4];
        this.originalArray = originalArray;
        buiildTree(0, originalArray.length, 1);
    }

    private void buiildTree(int start, int end, int index) {
        if (start == end -1) {
            segmentTree[index] = new SegmentTreeNode();
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
        buiildTree(start, mid, 2*index);
        buiildTree(mid, end, 2*index+1);
        segmentTree[index] = new SegmentTreeNode();
        segmentTree[index].val = -1;
        segmentTree[index].max = max(segmentTree[index * 2].max, segmentTree[index*2+1].max);
        segmentTree[index].min = min(segmentTree[index * 2].min, segmentTree[index * 2 + 1].min);
        segmentTree[index].sum =segmentTree[index*2].sum + segmentTree[index*2+1].sum;
        segmentTree[index].maxPrefixSum = max(segmentTree[index * 2].maxPrefixSum, segmentTree[index * 2].sum + segmentTree[index * 2 + 1].maxPrefixSum);
        segmentTree[index].maxPostFixSum = max(segmentTree[index * 2 + 1].maxPostFixSum, segmentTree[index * 2 + 1].sum + segmentTree[index * 2].maxPostFixSum);
        segmentTree[index].maxSubArraySum = max(segmentTree[index * 2].maxSubArraySum, max(segmentTree[index * 2 + 1].maxSubArraySum, segmentTree[2 * index].maxPostFixSum + segmentTree[2*index+1].maxPrefixSum));
    }

    public int getMaxSubArray(int x, int y) {
        return getMaxSubArray(0, originalArray.length, 1, x, y).maxSubArraySum;
    }

    private SegmentTreeNode getMaxSubArray(int start, int end, int index, int x, int y) {
        if (x <= start && y >= end) {
            return segmentTree[index];
        }

        if (x>=end || y <= start) {
            return null;
        }

        int mid = (start + end)/2;
        SegmentTreeNode left = getMaxSubArray(start, mid, 2*index, x, y);
        SegmentTreeNode right = getMaxSubArray(mid, end, 2*index+1, x, y);
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
        }
        SegmentTreeNode segmentTreeNode = new SegmentTreeNode();
        segmentTreeNode.maxSubArraySum = max(left.maxSubArraySum, max(right.maxSubArraySum, left.maxPostFixSum + right.maxPrefixSum));
        segmentTreeNode.maxPrefixSum = max(left.maxPrefixSum, left.sum + right.maxPrefixSum);
        segmentTreeNode.maxPostFixSum = max(right.maxPostFixSum, right.sum + left.maxPostFixSum);
        segmentTreeNode.sum = left.sum + right.sum;

        return  segmentTreeNode;
    }
}
