class Solution {
    public int smallestRangeII(int[] A, int K) {
        int n = A.length;
        int k = K;
        if (n == 1) return 0;
        Arrays.sort(A);
        int ans = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; ++i) {
            int l1 = A[0] + k;
            int r1 = A[i] + k;
            int l2 = A[i + 1] - k;
            int r2 = A[n - 1] - k;
            int[] tmp = {l1, l2, r1, r2};
            Arrays.sort(tmp);
            ans = Math.min(ans, tmp[tmp.length - 1] - tmp[0]);
        }
        return ans;
    }
}