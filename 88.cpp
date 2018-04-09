class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tot = n + m;
        int tmp = tot;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[--tot] = nums1[--m];
            } else {
                nums1[--tot] = nums2[--n];
            }
        }
        while (m > 0) {
            nums1[--tot] = nums1[--m];
        }
        while (n > 0) {
            nums1[--tot] = nums2[--n];
        }
    }
};