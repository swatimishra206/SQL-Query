
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Step 1: Target mil gaya
            if (nums[mid] == target) {
                return mid;
            }

            // Step 2: Check karo left half sorted hai ya nahi
            if (nums[start] <= nums[mid]) {

                // Target left sorted half ki range mein hai
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } 
                else {
                    start = mid + 1;
                }
            }

            // Step 3: Otherwise right half sorted hai
            else {

                // Target right sorted half ki range mein hai
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } 
                else {
                    end = mid - 1;
                }
            }
        }

        // Target array mein nahi mila
        return -1;
    }
};
