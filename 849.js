/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {
    let arr = seats.map((curr, index) => {
        if (curr == 1)  return index;
        return -1;
    });
    arr = arr.filter((curr) => curr != -1);
//    console.log(arr);
    let ans = 0;
    max = Math.max;
    for (let i = 1; i < arr.length; ++i) {
        ans = max(ans, Math.floor((arr[i] - arr[i - 1]) / 2));
    }
//    console.log(ans);
    ans = max(ans, arr[0], seats.length - arr[arr.length - 1] - 1);
    return ans;
};