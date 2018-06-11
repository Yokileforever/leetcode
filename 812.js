/**
 * @param {number[][]} points
 * @return {number}
 */
var largestTriangleArea = function(points) {
    let ans = 0;
    for (let i = 0; i < points.length; ++i) {
        for (let j = i + 1; j < points.length; ++j) {
            for (let k = j + 1; k < points.length; ++k) {
                let a = Math.sqrt((points[j][0] - points[k][0]) * (points[j][0] - points[k][0]) + (points[j][1] - points[k][1]) * (points[j][1] - points[k][1]));
                let b = Math.sqrt((points[i][0] - points[k][0]) * (points[i][0] - points[k][0]) + (points[i][1] - points[k][1]) * (points[i][1] - points[k][1]));
                let c = Math.sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));
             //   console.log(a + " " + b + " " + c);
                let cos = (a * a + b * b - c * c) / (2.0 * a * b);
                let sin = Math.sqrt((1 - cos * cos));
              //  console.log(a + " " + b + " " + sin);
              // console.log("ans = " + (a * b * sin * 0.5));
                ans = (ans < (a * b * sin * 0.5) ? (a * b * sin * 0.5) : ans);
            }
            
        }
    }
    return ans;
};