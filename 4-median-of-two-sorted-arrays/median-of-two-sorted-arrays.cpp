class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        int halfLen = (m + n + 1) / 2;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = halfLen - i;            

            int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightX = (i == m) ? INT_MAX : nums1[i];

            int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightY = (j == n) ? INT_MAX : nums2[j];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 1) {
                    return std::max(maxLeftX, maxLeftY);
                } else {
                    return (static_cast<double>(std::max(maxLeftX, maxLeftY)) + std::min(minRightX, minRightY)) / 2.0;
                }
            } else if (maxLeftX > minRightY) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0; 
    }
};