class Solution {
public:
    int count_pairs(vector<int>& a, int low, int mid, int high) {
        int c = 0, right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && 2LL * a[right] < (long long)a[i]) {
                right++;
            }
            c += (right - (mid + 1));
        }
        return c;
    }

    int merge_sort(vector<int>& a, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;

        int c = merge_sort(a, low, mid);
        c += merge_sort(a, mid + 1, high);
        c += count_pairs(a, low, mid, high);

        // Merge step
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (a[left] <= a[right]) temp.push_back(a[left++]);
            else temp.push_back(a[right++]);
        }
        while (left <= mid) temp.push_back(a[left++]);
        while (right <= high) temp.push_back(a[right++]);

        for (int i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }

        return c;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};
