#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <unistd.h>

using namespace std;

#define LL long long
#define pb push_back
#define mk make_pair
#define pill pair<int, int>
#define mst(a, b) memset(a, b, sizeof a)
#define lson (rt << 1)
#define rson ((rt << 1) | 1)

const int qq = 1e5 + 300;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int main() {
	vector<int> A;
	int k;
	int m;	scanf("%d", &m);
	for (int x, i = 0; i < m; ++i) {
		scanf("%d", &x);
		A.push_back(x);
	}
	int K;
	scanf("%d", &K);
	int n = (int)A.size();
    double dp[n + 5][K + 5];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = -INF;
        }
    }
    int sum[n + 5];
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + A[i - 1];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = K - 1; j >= 0; --j) {
        	for (int x = j ; x < i; ++x) {
        		if (dp[x][j] == -INF)	continue;
                if (dp[i][j + 1] == -INF)   dp[i][j + 1] = dp[x][j] + ((sum[i] - sum[x]) * 1.0) / (i - x);
        		else      dp[i][j + 1] = max(dp[i][j + 1], dp[x][j] + ((sum[i] - sum[x]) * 1.0) / (i - x));
        	}
        }
    }
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= K; ++j) {
    		printf("%lf ", dp[i][j]);
    	}
    	puts("");
    }
	return 0;
} 