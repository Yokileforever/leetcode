class Solution {
    int one, two;
    public int shortestBridge(int[][] A) {
        one = two = 0;
        int n = A.length;
        int m = A[0].length;
        int[] islandOneX = new int[n * m];
        int[] islandOneY = new int[n * m];
        int[] islandTwoX = new int[n * m];
        int[] islandTwoY = new int[n * m];
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] == 1) {
                    // System.out.println("6666");
                    if (cnt == 0)   dfs(i, j, A, islandOneX, islandOneY, cnt);
                    if (cnt == 1)   dfs(i, j, A, islandTwoX, islandTwoY, cnt);
                    cnt++;
                }
            }
        }
        // System.out.println("cnt = " + cnt);
        // System.out.println(one + " " + two);
        int minx = 1000000000;
        for (int i = 0; i < one; ++i) {
            for (int j = 0; j < two; ++j) {
                minx = Math.min(minx, Math.abs(islandOneX[i] - islandTwoX[j]) + Math.abs(islandOneY[i] - islandTwoY[j]));
            }
        }
        return minx - 1;
    }
    public void dfs(int X, int Y, int[][] A, int[] x, int[] y, int flag) {
        if (X < 0 || Y < 0) return;
        if (X >= A.length || Y >= A[0].length)  return;
        if (A[X][Y] == 0)   return;
        if (flag == 0) {
            x[one] = X;
            y[one] = Y;
            one++;
        } else {
            x[two] = X;
            y[two] = Y;
            two++;
        }    
        A[X][Y] = 0;
        dfs(X + 1, Y, A, x, y, flag);
        dfs(X - 1, Y, A, x, y, flag);
        dfs(X, Y + 1, A, x, y, flag);
        dfs(X, Y - 1, A, x, y, flag);
    }
}