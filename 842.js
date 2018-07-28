/**
 * @param {string} S
 * @return {number[]}
 */
var splitIntoFibonacci = function(S) {
    const maxn = 2147483647;
    var flag = false;
    function dfs(f1, f2, arr, id) {
        if (id === S.length) {
            flag = true;
        }
        if (flag)   return;
        let num = 0;
        for (let i = id; i < S.length; ++i) {
            num = num * 10 + parseInt(S.substr(i, 1));
            if (num > maxn)    continue;
            if (i - id + 1 > num.toString().length) {
                break;
            }
            if (num === f1 + f2) {
                arr.push(num);
                dfs(f2, num, arr, i + 1);
                break;
            }
        }
    }
    for (let i = 1; i < S.length - 1; ++i) {
        for (let j = i + 1; j < S.length; ++j) {
            let f1 = parseInt(S.slice(0, i));
            let f2 = parseInt(S.slice(i, j));
            if (f1 > maxn || f2 > maxn)    continue;
            if (i > f1.toString().length)   continue;
            if (j - i > f2.toString().length)   continue;
            let arr = [f1, f2];
            flag = false;
            dfs(f1, f2, arr, j);
            if (flag) {
                return arr;
            }
        }
    }
    return [];
};