class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())    return 0;
        stack<pair<int, int>> dp;
        int maxn = 0;
        for (int i = 0; i < (int)heights.size(); ++i) {
//            if (heights[i] == 0)    continue;
            maxn = max(maxn, heights[i]);
            if (dp.empty()) {
                dp.push(make_pair(heights[i], 1));
            } else if (dp.top().first < heights[i]) {
                maxn = max(maxn, dp.top().first * (dp.top().second + 1));
                dp.push(make_pair(heights[i], 1));
            } else {
                pair<int, int> tmp;
                tmp = make_pair(1e9, 0);
                while (!dp.empty() && dp.top().first >= heights[i]) {
                    tmp.second += dp.top().second;
                    tmp.first = min(tmp.first, dp.top().first);
                    maxn = max(maxn, tmp.first * tmp.second);
                    dp.pop();
                }
                dp.push(make_pair(heights[i], 1 + tmp.second));
            }
        }
        pair<int, int> tmp;
        tmp = dp.top();
        maxn = max(maxn, dp.top().first * dp.top().second);
        dp.pop();
        while (!dp.empty()) {
            tmp.second += dp.top().second;
            tmp.first = dp.top().first;
            dp.pop();
            maxn = max(maxn, tmp.first * tmp.second);
        }
        return maxn;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())    return 0;
        stack<int> dp;
        int maxn = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (dp.empty() || heights[dp.top()] <= heights[i]) {
                dp.push(i);
            } else {
                while (!dp.empty() && heights[dp.top()] > heights[i]) {
                    int a = heights[dp.top()];
                    dp.pop();
                    maxn = max(maxn, (dp.empty() ? i : i - 1 - dp.top()) * a);
                }
                dp.push(i);
            }
        }
        while (!dp.empty()) {
            int a = heights[dp.top()];
            dp.pop();
            maxn = max(maxn, (dp.empty() ? (int)heights.size() : (int)heights.size() - dp.top() - 1) * a);
        }
        return maxn;
    }
};