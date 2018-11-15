class Solution {
    public boolean repeatedSubstringPattern(String s) {
        if (s.length() == 0)    return false;
        int[] countAlp = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            countAlp[s.charAt(i) - 'a']++;
        }
        int gcd = -1;
        for (int i = 0; i < 26; ++i) {
            if (countAlp[i] == 0)   continue;
            if (gcd == -1) {
                gcd = countAlp[i];
            } else {
                gcd = Gcd(gcd, countAlp[i]);
            }
        }
//        System.out.println(gcd);
        if (gcd == 1)   return false;
//         int totalCount = 0;
//         for (int i = 0; i < 26; ++i) {
//             if (countAlp[i] == 0)   continue;
// //            System.out.println((i + 'a') + " = " + countAlp[i]);
//             totalCount += countAlp[i] / gcd;
//         }
//        System.out.println(gcd);
        for (int i = 2; i <= gcd; i++) {
//          System.out.println(s.charAt(i % totalCount) + " " + s.charAt(i));
            if (gcd % i == 0 && check(i, s)) {
//               System.out.println(i);
                return true;
            }
        }
        return false;
    }
    public boolean check(int period, String s) {
        int numberChar = s.length() / period;
        for (int i = numberChar; i < s.length(); ++i) {
            if (s.charAt(i) != s.charAt(i % numberChar)) {
                return false;
            }
        }
        return true;
    }
    public int Gcd(int a, int b) {
        return b == 0 ? a : Gcd(b, a % b);
    }
}