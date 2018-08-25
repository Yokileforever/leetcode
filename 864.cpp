#include <queue>
class Solution {
public:
    int convert(char ch) {
        if (ch == '@')  return 0;
        if (islower(ch)) {
            return ch - 'a' + 1;
        }
        return -1;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        if (!n)  return 0;
        int m = grid[0].size();
        if (!m) return 0;
        int start, end;
        int k = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int flag = convert(grid[i][j]);
                if (flag == 0) {
                    start = i, end = j;
                } else if (flag > 0) {
                    k++;
                }
            }
        }
//        printf("k = %d\n", k);
        struct Node {
            int x, y;
            int status;
            int step;
        }now, tmp;
        queue<Node> Q;
        int dp[n + 5][m + 5][1 << 8];
        memset(dp, -1, sizeof(dp));
        now.x = start, now.y = end, now.status = 1, now.step = 0;
        dp[start][end][1] = 0;
        
        Q.push(now);
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!Q.empty()) {
            now = Q.front();
            Q.pop();
//            printf("Node = %d %d\n", now.x, now.y);
            if (now.status == (1 << k) - 1) {
                return now.step;
            }
            for (int i = 0; i < 4; ++i) {
                int x = now.x + dx[i];
                int y = now.y + dy[i];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (grid[x][y] == '#')  continue;
                tmp.step = now.step + 1;
                tmp.status = now.status;
                if (isupper(grid[x][y])) {
                    int f = grid[x][y] - 'A' + 1;
                    if (now.status & (1 << f)) {
                        tmp.x = x, tmp.y = y;
                        if (dp[tmp.x][tmp.y][tmp.status] != -1) continue;
                        dp[tmp.x][tmp.y][tmp.status] = tmp.step;
                        Q.push(tmp);
                    }
                } else {
                    if (islower(grid[x][y])) {
                        tmp.status |= (1 << (grid[x][y] - 'a' + 1));
                    }
                    tmp.x = x, tmp.y = y;
                    if (dp[tmp.x][tmp.y][tmp.status] != -1) continue;
                    dp[tmp.x][tmp.y][tmp.status] = tmp.step;
                    Q.push(tmp);
                }
            }
        }
        return -1;
    }
};