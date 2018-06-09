/**
 * @param {string} S
 * @param {string} T
 * @return {string}
 */
var customSortString = function(S, T) {
    var ans = [];
    for (var i = 0, num; i < S.length; ++i) {
//      if (T.indexOf(S[i]) == -1)  continue;
        num = 0;
        T.split('').map(function(curr) {
            if (curr == S[i])   num++;
            return curr;
        });
        if (num == 0)   continue;
        ans = ans.concat(new Array(num).fill(S[i]));
    }
    var isvis = new Array(26).fill(-1);
    for (var i = 0, num; i < T.length; ++i) {
        if (S.indexOf(T[i]) != -1)  continue;
        if (isvis[T[i].charCodeAt() - 'a'.charCodeAt()] != -1) continue;
        isvis[T[i].charCodeAt() - 'a'.charCodeAt()] = 1;
        num = 0;
        T.split('').map(function(curr) {
            if (curr == T[i])   num++;
            return curr;
        });
        if (num == 0)   continue;
        ans = ans.concat(new Array(num).fill(T[i]));
    }
    return ans.join('');
};