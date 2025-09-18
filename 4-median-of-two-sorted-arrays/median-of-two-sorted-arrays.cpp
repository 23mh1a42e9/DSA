class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n % 2 == 0) {
            return (static_cast<double>(nums[n / 2 - 1]) + nums[n / 2]) / 2.0;
        } else {
            return static_cast<double>(nums[n / 2]);
        }
    }
};