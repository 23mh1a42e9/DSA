#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }

        std::vector<int> left_max(n);
        std::vector<int> right_max(n);
        int total_water = 0;

        // Populate the left_max array
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = std::max(height[i], left_max[i - 1]);
        }

        // Populate the right_max array
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = std::max(height[i], right_max[i + 1]);
        }
        
        // Calculate the trapped water
        for (int i = 0; i < n; ++i) {
            total_water += std::min(left_max[i], right_max[i]) - height[i];
        }

        return total_water;
    }
};