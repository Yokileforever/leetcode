class Solution {
     bool vis[105 + 5][105 + 5];
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0) return word.empty();
        int m = board[0].size();
        if (m == 0) return word.empty();
        bool f = false;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n && !f; ++i) {
            for (int j = 0; j < m && !f; ++j) {
                if (word[0] == board[i][j]) {
                    dfs(i, j, 0, (int)word.size(), f, n, m, board, word);
                }
            }
        }
        return f;
    }
    void dfs(int x, int y, int cnt, int k, bool &f, int n, int m, vector<vector<char>>& board, string &word) {
        if (cnt == k) {
            f = true;
            return ;
        }
        if (f)  return ;
        if (x < 0 || y < 0 || x >=n || y >= m) return ;
        if (board[x][y] != word[cnt])   return ;
        int tmp = board[x][y];
        board[x][y] = 0;
        dfs(x + 1, y, cnt + 1, k, f, n, m, board, word);
        dfs(x - 1, y, cnt + 1, k, f, n, m, board, word);
        dfs(x, y + 1, cnt + 1, k, f, n, m, board, word);
        dfs(x, y - 1, cnt + 1, k, f, n, m, board, word);
        board[x][y] = tmp;
        return ;
    }
};