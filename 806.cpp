class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 0, now = 0;
        for (int i = 0; i < S.size(); ++i) {
            int tmp = widths[S[i] - 'a'];
            if (line == 0) {
                line = 1, now = tmp;
            } else {
                if (now + tmp <= 100) {
                    now += tmp;
                } else {
                    line = line + 1;
                    now = tmp;
                }
            }
        }
        vector<int> ans;
        ans.push_back(line);
        ans.push_back(now);
        return ans;
    }
};