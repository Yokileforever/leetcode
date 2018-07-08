/**
 * @param {string[]} A
 * @return {number}
 */
var numSimilarGroups = function(A) {
    let fa = new Array(A.length).fill(-1);
    let find = (x) => {
        return fa[x] == -1 ? x : fa[x] = find(fa[x]);
    }
    let check = (x, y) => {
        let sum = 0;
        if (x.length != y.length)   return false;
        for (let i = 0; i < x.length; ++i) {
            if (x[i] != y[i])   sum++;
        }
        return sum === 2 || sum === 0;
    }
    for (let i = 0; i < A.length; ++i) {
        for (let j = i + 1; j < A.length; ++j) {
            if (check(A[i], A[j])) {
                let x = find(i);
                let y = find(j);
                if (x != y)
                    fa[y] = x;
            }
        }
    }
    return fa.reduce((prev, curr) => {
        return prev + (curr === -1 ? 1 : 0);
    }, 0);
};