/**
 * @param {string} S
 * @return {number}
 */
var uniqueLetterString = function(S) {
    let distance = [];
    for (let i = 0; i < 26; ++i) {
        distance[i] = [];
        distance[i].push(-1);
    }
    for (let i = 0; i < S.length; ++i) {
        let id = S.codePointAt(i) - 'A'.codePointAt(0);
        distance[id].push(i);
    }
    let ans = 0;
    for (let i = 0; i < 26; ++i) {
        distance[i].push(S.length);
        for (let j = 1; j < distance[i].length - 1; ++j) {
            let x = distance[i][j] - distance[i][j - 1];
            let y = distance[i][j + 1] - distance[i][j];
            ans += x * y;
        }
    }
    return ans;
};