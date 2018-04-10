class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n / 2, totalSum = accumulate(A.begin(), A.end(), 0);
        // early pruning
        bool isPossible = false;
        for (int i = 1; i <= m && !isPossible; ++i) {
            if (totalSum * i % n == 0) {
                isPossible = true;
            }
        }
        if (!isPossible)	return false;
        vector<unordered_set<int>> sums(m + 1);
        sums[0].insert(0);
        for (int num : A) {
            for (int i = m; i >= 1; --i) {
                for (const int t : sums[i - 1]) {
                    sums[i].insert(t + num);
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (totalSum * i % n == 0 && sums[i].find(totalSum * i / n) != sums[i].end()) {
                return true;
            }
        }
        return false;
    }
};