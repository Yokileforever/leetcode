class Solution {
    public int partitionDisjoint(int[] A) {
        int n = A.length;
        int[] maxn = new int[n];
        int[] minx = new int[n];
        for (int i = 0; i < n; ++i) {
            if (i == 0) maxn[i] = A[i];
            else    maxn[i] = Math.max(maxn[i - 1], A[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) minx[i] = A[i];
            else    minx[i] = Math.min(minx[i + 1], A[i]);
        }
        int ans = n;
        for (int i = 0; i < n - 1; ++i) {
            if (maxn[i] <= minx[i + 1]) {
                ans = i + 1;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) maxn[i] = A[i];
            else    maxn[i] = Math.max(maxn[i + 1], A[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) minx[i] = A[i];
            else    minx[i] = Math.min(minx[i - 1], A[i]);
        }
        for (int i = n - 1; i > 0; --i) {
            if (maxn[i] <= minx[i - 1]) {
                ans = Math.min(ans, n - i);
            }
        }
        return ans;
    }
}