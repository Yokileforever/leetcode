/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestIsland = function(grid) {
    if (grid.length == 0)   return 0;
    let vis = [];
    for (let i = 0; i < grid.length; ++i) {
        vis.push(new Array(grid[0].length).fill(0));
    }
    function dfs(x, y) {
        if (x < 0 || y < 0 || x >= grid.length || y >= grid[0].length || vis[x][y] == 1 || grid[x][y] == 0) {
            return 0;
        }
        vis[x][y] = 1;
        let ct = 1;
        ct = ct + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
        return ct;
    }
    let ans = 0;
    for (let i = 0; i < grid.length; ++i) {
       for (let j = 0; j < grid[i].length; ++j) {
           if (grid[i][j] == 0) {
               grid[i][j] = 1;
               ans = Math.max(dfs(i, j), ans);
               grid[i][j] = 0;
               for (let k = 0; k < grid.length; ++k) {
                   vis[k] = vis[k].fill(0);
               }
           }
       }
    }
    if (ans == 0)   ans = grid.length * grid[0].length;
    return ans;
};