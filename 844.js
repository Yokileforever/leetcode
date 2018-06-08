/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
    var x = [], y = [];
    for (i in S.split('')) {
        if (S[i] == '#') {
            if (x.length > 0)   x.pop();
        } else {
            x.push(S[i]);
        }
    }
    for (i in T.split('')) {
        if (T[i] == '#') {
            if (y.length > 0)   y.pop();
        } else {
            y.push(T[i]);
        }
    }
    return x.join('') == y.join('');
};