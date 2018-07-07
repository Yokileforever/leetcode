/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A) {
    let i = 0;
    while (A[i + 1] > A[i]) i++;
    return i;
};