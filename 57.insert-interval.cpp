/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (28.85%)
 * Total Accepted:    120.9K
 * Total Submissions: 419K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * 
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * 
 * 
 * 
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 * 
 * 
 * 
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		intervals.push_back(newInterval);
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
