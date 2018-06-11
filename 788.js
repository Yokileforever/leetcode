/**
 * @param {number} N
 * @return {number}
 */
var rotatedDigits = function(N) {
    let arr = new Array(N).fill().map(function(item, index) {
        return index + 1;
    });
    let ans = 0;
    for (let i = 0; i < N; ++i) {
        let cur = arr[i];
        let f = 1;
        while (cur > 0) {
            let tmp = cur % 10;
            if (tmp == 3 || tmp == 4 || tmp == 7)   f *= 0;
            else if (tmp == 2 || tmp == 5 || tmp == 6 || tmp == 9)   f *= 2;
            else    f *= 1;
            cur = Math.floor(cur /= 10);
        }
        // if (f >= 2)
        //     console.log(arr[i] + " " + f);
        if (f >= 2) ans++;
    }
        return ans;
};