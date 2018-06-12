class Solution {
    
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int n = routes.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                ans.push_back(routes[i][j]);
            }
            sort(routes[i].begin(), routes[i].end());
        }
        sort(ans.begin(), ans.end());
        unique(ans.begin(), ans.end());
        int mar[n + 5][n + 5];
        const int INF = 1e9 + 10;
        for (int i = 0; i < n + 5; ++i) {
            fill(mar[i], mar[i] + n + 5, INF);
            mar[i][i] = 0;
        }
        vector<int>:: iterator it;
        vector<int> u, v;
        for (int i = 0; i < n; ++i) {
            for (int x = 0; x < routes[i].size(); ++x) {
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    it = lower_bound(routes[j].begin(), routes[j].end(), routes[i][x]);
                    if (it == routes[j].end())  continue;
                    if (*it == routes[i][x])    mar[i + 1][j + 1] = mar[j + 1][i + 1] = 1;
                }
            }
            for (int j = 0; j < routes[i].size(); ++j) {
                if (routes[i][j] == S)  u.push_back(i + 1);
                if (routes[i][j] == T)  v.push_back(i + 1);
            }
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                if (mar[i][k] == INF)   continue;
                for (int j = 1; j <= n; ++j) {
                    if (mar[k][j] == INF)   continue;
                    mar[i][j] = min(mar[i][j], mar[i][k] + mar[k][j]);
                }
            }
        }
        int minx = INF;
        // cout << u.size() << endl;
        // cout << v.size() << endl;
        for (int i = 0; i < u.size(); ++i) {
            for (int j = 0; j < v.size(); ++j) {
                minx = min(minx, mar[u[i]][v[j]]);
            }
        }
        if (minx == INF)    minx = -2;
        return minx + 1;
    }
};