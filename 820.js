/**
 * 注意这里是从某个索引匹配要一直匹配到#号才算一个字符串
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    words.sort((s1, s2) => {
        if (s1.length === s2.length) {
            if (s1 > s2) {
                return 1;
            } 
            return -1;
        }
        return s2.length - s1.length;
    })
//    console.log(words);
    return words.reduce((prev, curr) => {
        if (prev.length === 0) {
            return curr + '#';
        }
        if (prev.indexOf((curr + '#')) !== -1) return prev;
        return prev + curr + '#';
    }, '').length;
};