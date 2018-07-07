/**
 * @param {string} S
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(S, shifts) {
    if (shifts.lengt == 0)  return '';
    shifts = shifts.reverse();
    for (let i = 1; i < shifts.length; ++i) {
        shifts[i] = shifts[i - 1] + shifts[i];
    }
    shifts = shifts.reverse();
    S = S.split('');
    for (let i = 0; i < shifts.length; ++i) {
        let ch = (S[i].codePointAt(0) - 'a'.codePointAt(0) + shifts[i]) % 26;
        S[i] = String.fromCodePoint(ch + 'a'.codePointAt(0));
    }
    return S.join('');
};