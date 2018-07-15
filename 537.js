/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var complexNumberMultiply = function(a, b) {
    let addIndex = a.indexOf('+');
    let a1 = Number.parseInt(a.slice(0, addIndex));
    let b1 = Number.parseInt(a.slice(addIndex + 1, -1));
    addIndex = b.indexOf('+');
    let a2 = Number.parseInt(b.slice(0, addIndex));
    let b2 = Number.parseInt(b.slice(addIndex + 1, -1));
//    console.log(a1, b1);
//    console.log(a2, b2);
    let x = a1 * a2 + b1 * b2 * (-1);
    let y = a1 * b2 + b1 * a2;
    return x + '+' + y + 'i';
};