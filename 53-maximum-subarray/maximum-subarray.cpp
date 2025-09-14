class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int MaxEnding = nums[0];
        
        for (int i = 1; i < n; i++) {
            MaxEnding = max(MaxEnding + nums[i], nums[i]);
            res = max(res, MaxEnding);
        }
        
        return res;
    }
};
