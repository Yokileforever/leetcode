class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int nxt[needle.size() + 5];
        nxt[0] = -1;
        int i = 0, j = -1;
        while (i < needle.size()) {
            if (j == -1 || needle[i] == needle[j]) {
                nxt[++i] = ++j;
            } else {
                j = nxt[j];
            }
        }
        i = 0, j = 0;
        bool f = false;
        while (i < haystack.size()) {
            
            if (j == -1 || haystack[i] == needle[j]) {
                ++i, ++j;
            } else {
                j = nxt[j];
            }
//            printf("%d %d\n", i, j);
            if (j >= (int)needle.size()) {
                f = true;
                break;
            }
            
        }
        int ans;
//        printf("%d %d\n", i, j);
        if (!f) ans = -1;
        else    ans = i - needle.size();
        return ans;
    }
};