class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        int cnt = 0;
        while (l <= r) {
//            printf("%c  %c\n", s[l], s[r]);
            if (s[l] != s[r]) {
                if (cnt > 0)    break;
                cnt++;
                if (s[l + 1] == s[r]) {
                    l++;
                } else {
                    break;
                }
            }
            l++, r--;
        }
        if (l >= r)  return true;
        l = 0, r = n - 1;
        cnt = 0;
        while (l <= r) {
//            printf("%c  %c\n", s[l], s[r]);
            if (s[l] != s[r]) {
                if (cnt > 0)    break;
                cnt++;
                if (s[r - 1] == s[l]) {
                    r--;
                } else {
                    break;
                }
            }
            l++, r--;
        }
        if (l >= r)  return true;
        return false;
    }
};

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                return isValid(s, l + 1, r) || isValid(s, l, r - 1);
            }
            l++, r--;
        }
        return true;
    }
    bool isValid(string &s, int l, int r) {
        if (l >= r) return true;
        if (s[l] != s[r])    return false;
        return isValid(s, l + 1, r - 1);
    }
};