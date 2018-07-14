/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxIncreaseKeepingSkyline = function(grid) {
    if (grid.length === 0)    return grid;
    let row = new Array(grid.length).fill(0);
    let col = new Array(grid[0].length).fill(0);
    grid.forEach((arr, i) => arr.forEach((value, j) => {
        row[i] = Math.max(row[i], value);
        col[j] = Math.max(col[j], value);
    }));
    let convert = grid.map((arr, i) => arr.map((value, j) => Math.min(row[i], col[j]) ));
//    console.log(convert);
//    console.log(grid);
    return grid.reduce((prev, arr, i) => prev + arr.reduce((prev, value, j) => prev + convert[i][j] - grid[i][j], 0), 0)
};