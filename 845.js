/**
 * @param {number[]} A
 * @return {number}
 */
var longestMountain = function(A) {
    let [flag, maxn, count] = [true, 0, 1];
    for (let i = 1; i < A.length; ++i) {
        if (A[i] == A[i - 1]) {
            flag = true;
            count = 1;
        } else {
            if (A[i] > A[i - 1]) {
                if (flag) {
                    count++;
                } else {
                    count = 2;
                    flag = true;
                }
            } else {
                if (flag && count > 1) {
                    flag = false;
                }
                if (!flag) {
                    count++;
                } else {
                    flag = true;
                    count = 1;
                }
            }
        }
//        console.log(count);
        if (flag == false && count > 2) {
            maxn = Math.max(maxn, count);
        }
    }
    return maxn;
};