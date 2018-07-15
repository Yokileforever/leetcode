/**
 * @param {number[][]} graph
 * @return {boolean}
 */
var isBipartite = function(graph) {
    let n = graph.length;
    let isKind = new Array(n).fill(-1);
    function dfs(u, shouldKind) {
        if (isKind[u] === shouldKind)   return true;
        if (isKind[u] !== -1) return false;
        isKind[u] = shouldKind;
        let ans = true;
        for (let i = 0; i < graph[u].length; ++i) {
            let v = graph[u][i];
            ans = ans && dfs(v, shouldKind ^ 1);
        }
        return ans;
    }
    let ans = true;
    for (let i = 0; i < n; ++i) {
        if (isKind[i] === -1)
            ans = ans && dfs(i, 0);
    }
    return ans;
};