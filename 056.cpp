/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (31.77%)
 * Total Accepted:    185.5K
 * Total Submissions: 583.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty())	return vector<Interval>();
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
		vector<Interval> ans;
		int l = -1, r = -1;
		for (int i = 0; i < intervals.size(); ++i) {
			if (l == -1 && r == -1) {
				l = intervals[i].start;
				r = intervals[i].end;
			} else if (intervals[i].start <= r) {
				r = max(r, intervals[i].end);
			} else if (intervals[i].start > r) {
				ans.push_back(Interval(l, r));
				l = intervals[i].start, r = intervals[i].end;
			}
		}
		ans.push_back(Interval(l, r));
		return ans;
	}
};
