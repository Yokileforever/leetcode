/**
 * @param {string} S
 * @return {number}
 */
var scoreOfParentheses = function(S) {
    let arr = [];
    let match = new Array(S.length).fill(0);
    for (let i = 0; i < S.length; ++i) {
        if (S[i] === '(') {
            arr.push(i);
        } else {
            match[arr.pop()] = i;
        }
    }
    return dfs(0, S.length - 1, S, match);
};

dfs = (start, end, S, match) => {
//    console.log(start, end);
    if (start + 1 === end) {
        return 1;
    }
    if (match[start] === end) {
        return 2 * dfs(start + 1, end - 1, S, match);
    } else {
        return dfs(start, match[start], S, match) + dfs(match[start] + 1, end, S, match);
    }
}