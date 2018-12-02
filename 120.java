class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null) return 0;
        int n = triangle.size();
        int[] dp = new int[n + 1];
        dp[0] = triangle.get(0).get(0);
        for (int i = 1; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0) {
                    dp[j] += triangle.get(i).get(j);
                } else if (j == i) {
                    dp[j] = triangle.get(i).get(j) + dp[j - 1];
                } else {
                    dp[j] = Math.min(dp[j], dp[j - 1]) + triangle.get(i).get(j);
                }
            }
        }
        int minx = 1000000000;
        for (int i = 0; i < n; ++i) {
            minx = Math.min(minx, dp[i]);
        }
        return minx;
    }
}

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null) return 0;
        int n = triangle.size();
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < triangle.get(i).size(); ++j) {
                int minxNext = Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1));
                
                triangle.get(i).set(j, minxNext + triangle.get(i).get(j));
            }
        }
        return triangle.get(0).get(0);
    }
}