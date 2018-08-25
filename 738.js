/**
 * @param {number} N
 * @return {number}
 */
var monotoneIncreasingDigits = function(N) {
    if (N == 0) return 0;
    let arr = [];
    while (N > 0) {
        arr.push(N % 10);
        N = Math.floor(N / 10);
    }
    for (let i = arr.length - 1; i > 0; --i) {
        if (arr[i] > arr[i - 1]) {
            let index = arr.lastIndexOf(arr[i]);
            arr[index] = arr[index] - 1;
            arr.fill(9, 0, index);
            break;
        }
    }
    
    return parseInt(arr.reverse().join(''));
};