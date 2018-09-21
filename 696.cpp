class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<pair<int, int>> p;
        int pre = -1, countNum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (pre == -1 || pre == s[i] - '0') {
                pre = s[i] - '0';
                countNum++;
            } else {
                p.push_back(make_pair(pre, countNum));
                pre = s[i] - '0';
                countNum = 1;
            }
        }
        p.push_back(make_pair(pre, countNum));
        int ans = 0;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i].first != p[i - 1].first) {
                ans += min(p[i].second, p[i - 1].second);
            }
        }
        return ans;
    }
};