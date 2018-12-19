/**
 * 状态机
 */

class Solution {
    public boolean isNumber(String s) {
        s = s.trim().toLowerCase();
        
        boolean numBeforeE = false;
        boolean numAfterE = false;
        int state = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (Character.isDigit(ch)) {
                if (state <= 2) state = 2;
                else if (state <= 4)    state = 4;
                else if (state <= 7)    state = 7;
                else    return false;
                if (state <= 4) numBeforeE = true;
                if (state > 4)  numAfterE = true;
            } else if (ch == '+' || ch == '-') {
                if (state == 0 || state == 5)   state++;
                else   return false;
            } else if (ch == '.') {
                if (state <= 2) state = 3;
                else    return false;
            } else if (ch == 'e') {
                if (2 <= state && state <= 4)   state = 5;
                else    return false;
            } else {
                return false;
            }
        }
        return numBeforeE && Arrays.asList(2, 3, 4).contains(state) || numBeforeE && numAfterE;
    }
}