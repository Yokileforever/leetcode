/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    let trans = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    let obj = {};
    for (let i = 0; i < words.length; ++i) {
        let tmp = "";
        for (let j = 0; j < words[i].length; ++j) {
            tmp = tmp + trans[words[i][j].charCodeAt() - 'a'.charCodeAt()];
        }
        
        obj[tmp] = obj[tmp] ? obj[tmp] + 1 : 1; 
    }
    let num = 0;
    for (let i in obj) {
        num++;
    }
    return num;
};