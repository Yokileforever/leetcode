class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int r1 = (int)a.size() - 1, r2 = (int)b.size() - 1;
        int tmp = 0;
        while (r1 >= 0 || r2 >= 0) {
            int x, y, p;
            if (r1 >= 0)    x = a[r1] - '0';
            else            x = 0;
            
            if (r2 >= 0)    y = b[r2] - '0';
            else            y = 0;
            
            p = x + y + tmp;
            ans = (p % 2 == 0 ? "0" : "1") + ans;
            tmp = p / 2;
            r1--, r2--;
        }
        if (tmp > 0)    ans = "1" + ans;
        return ans;
    }
};