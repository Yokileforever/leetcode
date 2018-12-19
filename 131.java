class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> list = new ArrayList<List<String>>();
        if (s == null) return list;
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j + i - 1 < n; ++j) {
                int l = j, r = j + i - 1;
                if (l == r) {
                    dp[l][r] = true;
                } else if (l + 1 == r) {
                    if (s.charAt(l) == s.charAt(r)) {
                        dp[l][r] = true;
                    }
                } else {
                    if (s.charAt(l) == s.charAt(r)) {
                        dp[l][r] = dp[l + 1][r - 1];
                    }
                }
            }
        }
        dfs(dp, list, s, 0, new ArrayList<String>());
        return list;
    }
    public void dfs(boolean[][] dp, List<List<String>> list, String s, int start, List<String> tmpArray) {
        if (start == s.length()) {
            list.add(new ArrayList(tmpArray));
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (dp[start][i] == true) {
                tmpArray.add(s.substring(start, i + 1));
                dfs(dp, list, s, i + 1, tmpArray);
                tmpArray.remove(tmpArray.size() - 1);
            }
        }
    }
}