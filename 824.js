/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    S = S.split(' ');
    let arr = [];
    let tail = "a";
    for (let i in S) {
        console.log(S[i]);
        let st = S[i].toLowerCase();
        if (st[0] == 'a' || st[0] == 'e' || st[0] == 'i' || st[0] == 'o' || st[0] == 'u') {
            arr.push(S[i] + "ma"  + tail);
        } else {
            S[i] = S[i].split('');
            S[i].push(S[i].shift());
            arr.push(S[i].join('') + "ma" + tail);
        }
        tail = tail + "a";
    }
    return arr.join(' ');
};