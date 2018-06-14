/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
    let sum = 0, list = [];
    for (i in ops) {
        if (ops[i] == "C") {
            if (list.length > 0) {
                list.pop();  
            }
        } else if (ops[i] == "D") {
            list.push(list[list.length - 1] * 2);
        } else if (ops[i] == "+") {
            list.push(list[list.length - 1] + list[list.length - 2]);
        } else {
            list.push(parseInt(ops[i]));
        }
    }
    return list.reduce((prev, curr) => prev + curr);
};