class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length(), m = t.length();
        int[][] dp = new int[n + 5][m + 5];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (t.charAt(j - 1) != s.charAt(i - 1)) {
                    //System.out.print(dp[i][j] + " ");
                    continue;
                }
                if (i < j)  continue;
                if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    for (int k = i - 1; k >= j - 1; --k) {
                        if (s.charAt(k - 1) == t.charAt(j - 2)) {
                            dp[i][j] += dp[k][j - 1];
                        }
                    }
                }
               // System.out.print(dp[i][j] + " ");
            }
            // System.out.println("");
        }
        int ans = 0;
        for (int i = m; i <= n; ++i) {
//            System.out.println("i = " + i + " ans = " + dp[i][m]);
            if (s.charAt(i - 1) == t.charAt(m - 1))
                ans += dp[i][m];
        }
        // System.out.println(dp[6][2]);
        // System.out.println(dp[2][2]);
        return ans;
    }
}