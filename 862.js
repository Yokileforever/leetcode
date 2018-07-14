/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var shortestSubarray = function(A, K) {
    let n = A.length;
    let sum = new Array(n + 1);
    sum[0] = 0;
    for (let i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + A[i - 1];
    }
    let queue = [0];
    let ans = n + 1;
    for (let i = 1; i <= n; ++i) {
        let value = sum[i], index = i;
        while (queue.length > 0 && value < sum[queue[queue.length - 1]]) {
            queue.pop();
        }
        while (queue.length > 0 && value - K >= sum[queue[0]]) {
            ans = Math.min(ans, index - queue.shift());
        }
        queue.push(index);
    }
    if (ans > n)    ans = -1;
    return ans;
};