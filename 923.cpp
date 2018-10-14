class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int numCount[305];
        memset(numCount, 0, sizeof(numCount));
        for (int i = 0; i < A.size(); ++i) {
            numCount[A[i]]++;
        }
        long long ans = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i <= target; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (i + j > target) continue;
                for (int k = 0; k <= target; ++k) {
                    if (i != j && i != k && j != k) continue;
                    if (!(i <= j && j <= k))    continue;
                    int sum = i + j + k;
                    if (sum != target)  continue;
                    if (numCount[i] == 0 || numCount[j] == 0 || numCount[k] == 0)   continue;
                    if (i == j && j == k) {
                        if (numCount[i] < 3)    continue;
                        long long p = numCount[i];
                        ans = (ans + p * (p - 1) * (p - 2) / 6 % MOD) % MOD;
                    } else if (i == j) {
                        if (numCount[i] < 2)    continue;
                        long long p = numCount[i];
                        ans = (ans + p * (p - 1) / 2 * numCount[k]) % MOD;
                    } else if (i == k) {
                        if (numCount[i] < 2)    continue;
                        long long p = numCount[i];
                        ans = (ans + p * (p - 1) / 2 * numCount[j]) % MOD;
                    } else if (j == k) {
                        if (numCount[j] < 2)    continue;
                        long long p = numCount[j];
                        ans = (ans + p * (p - 1) / 2 * numCount[i]) % MOD;
                    }
                }
            }
        }
//        printf("%lld\n", ans);
        for (int i = 0; i <= target; ++i) {
            for (int j = i + 1; j <= target; ++j) {
                for (int k = j + 1; k <= target; ++k) {
                    int sum = i + j + k;
                    if (sum != target)  continue;
                    if (numCount[i] == 0 || numCount[j] == 0 || numCount[k] == 0)   continue;
                    ans = (ans + numCount[i] * numCount[j] * numCount[k] % MOD) % MOD;
                }
            }
        }
        return ans;
    }
};