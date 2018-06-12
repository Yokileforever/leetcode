/**
 * @param {string} S
 * @return {number[][]}
 */
var largeGroupPositions = function(S) {
    var index = [0, 0];
    var res = [];
    for (var i=0; i<S.length; i++) {
        if (i===S.length-1 || S[i] !== S[i+1]) {
            index[1] = i;
            if (index[1] - index[0] >= 2) {
                res.push(index);
            }
            index = [i+1, i+1];
        }
    }
    return res;
};

/**
 * @param {string} S
 * @return {number[][]}
 */
var largeGroupPositions = function(S) {
    let ch = '$', cnt = 0;
    let ans = [];
    for (let i in S) {
        if (S[i] == ch) {
            cnt++;
        } else {
            if (cnt >= 3) {
                let tmp = [];
                tmp.push(i - cnt);
                tmp.push(i - 1);
                ans.push(tmp);
            }
            cnt = 1;
            ch = S[i];
        }
//        console.log(cnt);
    }
    
    if (cnt >= 3) {
        let tmp = [];
        tmp.push(S.length - cnt);
        tmp.push(S.length - 1);
        ans.push(tmp);
    }
    return ans;
};