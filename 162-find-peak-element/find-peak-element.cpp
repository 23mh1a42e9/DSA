
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n=nums.size();
       // Edge case: A single element array is a peak.
       if(n == 1) {
           return 0;
       }
       // Check if the first element is a peak.
       if(nums[0] > nums[1]) {
           return 0;
       }
       // Check if the last element is a peak.
       if(nums[n-1] > nums[n-2]) {
           return n-1;
       }
       // Binary search for a peak in the middle of the array.
       int low=1, high=n-2;
       while(low <= high){
            int mid= low + (high-low)/2; // Prevents integer overflow
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            // If the element to the left is greater, a peak must be in the left half.
            else if(nums[mid-1] > nums[mid]) { 
                high = mid - 1;
            }
            // If the element to the right is greater, a peak must be in the right half.
            else { 
                low = mid + 1;
           }
       }
       // This line should technically be unreachable, as a peak is guaranteed to exist.
       return -1;
    }
};