/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function(bills) {
    let moneyCount = new Array(25).fill(0);
    let cu = 0;
    return bills.every((curr) => {
//        console.log(++cu);
        if (curr === 5) {
            moneyCount[5]++;
            return true;
        }
        if (curr === 10) {
            moneyCount[5]--;
            moneyCount[10]++;
            return moneyCount[5] >= 0;
        }
        if (curr === 20) {
            if (moneyCount[10] > 0 && moneyCount[5] > 0) {
                moneyCount[10]--;
                moneyCount[5]--;
            } else if (moneyCount[5] >= 3) {
                moneyCount[5] -= 3;
            } else {
                return false;
            }
            moneyCount[20]++;
            return true;
        }
    });
};