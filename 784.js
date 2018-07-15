/**
 * @param {string} S
 * @return {string[]}
 */
var letterCasePermutation = function(S) {
    let ans = new Array();
//    console.log('x'+ S[0]);
    function dfs(str, index) {
        if (index === S.length) {
            ans.push(str);
            return ;
        }
        dfs(str + (S[index].toLowerCase()), index + 1);
        const patten = /[a-zA-Z]/;
        if (patten.test(S[index])) {
            dfs(str + (S[index].toUpperCase()), index + 1);
        }
    }
    dfs('', 0);
    return ans;
};