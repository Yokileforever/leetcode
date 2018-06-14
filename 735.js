/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    let arr = [];
    for (let i in asteroids) {
        if (arr.length == 0) {
            arr.push(asteroids[i]);
        } else if (!(asteroids[i] < 0 && arr[arr.length - 1] >= 0)) {
//            console.log(i);
            arr.push(asteroids[i]);
        } else {
            while (arr.length > 0 && (asteroids[i] < 0 && arr[arr.length - 1] >= 0) && Math.abs(asteroids[i]) > Math.abs(arr[arr.length - 1])) {
                arr.pop();
            }
            if (arr.length == 0) {
                arr.push(asteroids[i]);
            } else if (!(asteroids[i] < 0 && arr[arr.length - 1] >= 0)) {
                       arr.push(asteroids[i]);
            } else if ((asteroids[i] < 0 && arr[arr.length - 1] >= 0) && Math.abs(arr[arr.length - 1]) == Math.abs(asteroids[i])) {
                
                arr.pop();
            } 
        }
    }
    return arr;
};