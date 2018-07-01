/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
    if (graph.length == 1 && graph[0].length == 0) return 0;
    const MAX = 1e9;
    let dis = new Array(graph.length);
    for (let i = 0; i < graph.length; ++i) {
        dis[i] = new Array(graph.length).fill(MAX);
        for (let j = 0; j < graph[i].length; ++j) {
            dis[i][graph[i][j]] = 1;
        }
    }
    let min = Math.min;
    let n = graph.length;
    for (let k = 0; k < n; ++k) {
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
//    console.log(dis);
    let ans = MAX;
    for (let i = 0; i < n; ++i) {
        let dp = new Array(1 << n);
        for (let j = 0; j < (1 << n); ++j) {
            dp[j] = new Array(n).fill(MAX);
        }
//        console.log(dp);
//        console.log(typeof dp[1 << 1][i]);
        // for (let j = 0; j < (1 << n); ++j) {
        //     for (let k = 0; k < n; ++k) {
        //         console.log(dp[j][k]);
        //     }
        // }
        dp[1 << i][i] = 0;
        for (let j = (1 << i); j < (1 << n); ++j) {
            for (let k = 0; k < n; ++k) {
                if (dp[j][k] == MAX) {
                    continue;
                }
                for (let next = 0; next < n; ++next) {
                    if ((j & (1 << next)) > 0)   continue;  //注意>的优先级比&运算符要高
                    dp[j | (1 << next)][next] = min(dp[j | (1 << next)][next], dp[j][k] + dis[k][next]);
                }
            }
        }
        for (let j = 0; j < n; ++j) {
            if (j != i) {
                ans = min(ans, dp[(1 << n) - 1][j]);                        
            }
        }
//        console.log(ans);
    }
    return ans;
};