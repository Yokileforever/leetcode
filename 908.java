class Solution {
    public int smallestRangeI(int[] A, int K) {
        int k = K;
        int maxn = Arrays.stream(A).max().getAsInt();
        int minx = Arrays.stream(A).min().getAsInt();
        int n = A.length;
        if (maxn - minx <= 2 * k) {
            int target = (maxn + minx) / 2;
            for (int i = 0; i < n; ++i) {
                A[i] = target;
            }
            return 0;
        } else {
            int l = minx + k;
            int r = maxn - k;
            for (int i = 0; i < n; ++i) {
                if (A[i] + k >= l)  A[i] = l;
                else if (A[i] - k <= r)  A[i] = r;
            }
            return r - l;
        }
    }
}