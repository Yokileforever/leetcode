class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans(A.size());
        int even = 0, odd = 1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] % 2 == 0) {
                ans[even] = A[i];
                even += 2;
            } else {
                ans[odd] = A[i];
                odd += 2;
            }
        }
        return ans;
    }
    
};