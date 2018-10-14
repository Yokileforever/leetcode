class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == ')') {
                if (st.empty()) {
                    ans++;
                } else {
                    st.pop();
                }
            } else {
                st.push(S[i]);
            }
        }
        return ans + st.size();
    }
};