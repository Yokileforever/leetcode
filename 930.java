class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int[] prefix = new int[30005];
        prefix[0]++;
        int ans = 0;
        int now = 0;
        for (int i = 0; i < A.length; ++i) {
            now += A[i];
            if (now - S >= 0) {
                ans += prefix[now - S];
            }
            prefix[now]++;
        }
        return ans;
    }
}