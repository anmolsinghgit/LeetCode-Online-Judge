// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://github.com/haoel/leetcode
class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l = m + n;
        if (l & 0x01) {
            return this->findKth(nums1, nums2, l / 2 + 1);
        } else {
            return (this->findKth(nums1, nums2, l / 2) + this->findKth(nums1, nums2, l / 2 + 1)) / 2.0;
        }
    }
private:
    int findKth(const vector<int>& nums1, const vector<int>& nums2, const int& k) {
        int m = nums1.size();
        int n = nums2.size();
        int l = m + n;
        if (m > n) return this->findKth(nums2, nums1, k);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1.front(), nums2.front());
        int idxA = min(k / 2, m);
        int idxB = k - idxA;
        if (nums1[idxA - 1] < nums2[idxB - 1]) {
            vector<int> newNums1(nums1.begin() + idxA, nums1.end());
            return this->findKth(newNums1, nums2, k - idxA);
        }
        else if (nums1[idxA - 1] > nums2[idxB - 1]) {
            vector<int> newNums2(nums2.begin() + idxB, nums2.end());
            return this->findKth(nums1, newNums2, k - idxB);
        }
        else {
            return nums1[idxA - 1];
        }
    }
};
