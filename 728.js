/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function(left, right) {
//    console.log(new Array(right - left + 1).fill(0));
    let arr = new Array(right - left + 1).fill(0).map(x => left++);
//    console.log(arr);
    return arr.filter(function(x) {
        let cur = x;
        while (cur > 0) {
            let tmp = cur % 10;
            if (tmp == 0)   return false;
            if (x % tmp != 0)   return false;
            cur = (Math.floor(cur / 10));
        }
        return true;
    });
};