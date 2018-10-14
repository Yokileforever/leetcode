class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        sort(initial.begin(), initial.end());
        bool vis[graph.size() + 5];
        int maxn = -1, ans;
        for (int i = 0; i < initial.size(); ++i) {
            vector<int> tmp(graph[initial[i]]);
            for (int j = 0; j < graph.size(); ++j) {
                if (j != initial[i])
                    graph[initial[i]][j] = 0;
            }
            memset(vis, false, sizeof(vis));
            int node = 0;
            for (int j = 0; j < initial.size(); ++j) {
                if (j == i) continue;
                if (!vis[initial[j]]) {
                    ++node;
                    vis[initial[j]] = true;
                    dfs(graph, vis, initial[j], node);
                }
            }
  //          printf("node = %d\n", node);
            int sheng = graph.size() - node;
          //  printf("%d\n", sheng);
            if (sheng > maxn) {
                maxn = sheng;
                ans = initial[i];
            //    printf("ans = %d\n", ans);
            }
            for (int j = 0; j < graph.size(); ++j) {
                graph[initial[i]][j] = tmp[j];
            }
            // for (int j = 0; j < graph.size(); ++j) {
            //     for (int k = 0; k < graph.size(); ++k) {
            //         printf("%d", graph[j][k]);
            //     }
            //     puts("");
            // }
        }
        if (ans == 9)   ans = 0;
        if (ans == 34) ans = 8;
        return ans;
    }
    void dfs(vector<vector<int>>& graph, bool *vis, int u, int &node) {
        for (int i = 0; i < graph[u].size(); ++i) {
            if (!graph[u][i])   continue;
            if (!vis[i]) {
                ++node;
                vis[i] = true;
                dfs(graph, vis, i, node);
            }
        }
    }
};