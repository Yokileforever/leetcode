/**
 * @param {number[]} hand
 * @param {number} W
 * @return {boolean}
 */
var isNStraightHand = function(hand, W) {
    if (hand.length % W != 0) {
        return false;
    }
    if (W == 1) {
        return true;
    }
    let map = new Map();
    hand.sort(function(a, b) {
        return a - b;
    });
    for (let i = 0; i < hand.length; ++i) {
        if (map.has(hand[i])) {
            map.set(hand[i], map.get(hand[i]) + 1);
        } else {
            map.set(hand[i], 1);
        }
    }
//    console.log(map);
//    console.log(typeof map.size);
    let length = map.size + 1;
//    console.log(typeof length);
//    console.log(length);
    let arr = new Array(length).fill(0);
    let [cards, pre] = [0, null];
    let i = 0;
    for (let [key, value] of map) {
//        console.log(typeof value);
        cards -= arr[i];
        if (cards > 0 && key - 1 != pre)    return false; 
//        console.log(key + " " + value);
        if (value < cards)  return false;
        arr[i + W] += value - cards;
        cards = cards + (value - cards);
        pre = key;
        i++;
    }
//    console.log(cards);
    cards -= arr[i]; 
    return cards == 0;
};