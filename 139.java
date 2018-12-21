class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] dp = new boolean[n + 5];
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            String substring = s.substring(0, i);
            for (String word : wordDict) {
                if (word.length() > substring.length()) continue;
                if (substring.endsWith(word)) {
                    dp[i] |= dp[substring.length() - word.length()];
                }
            }
        }
        return dp[n];
    }
    public boolean dfs(int start, String s, List<String> wordDict) {
        if (start == s.length()) {
            return true;
        }
        boolean f = false;
        for (int i = start; i < s.length(); ++i) {
            if (wordDict.contains(s.substring(start, i + 1))) {
                f = f | dfs(i + 1, s, wordDict);
            }
            if (f)  break;
        }
        return f;
    }
}