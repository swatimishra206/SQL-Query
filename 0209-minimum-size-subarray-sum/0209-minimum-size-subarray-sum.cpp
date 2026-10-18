
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int sum = 0;
        int ans = n + 1;

        for (int end = 0; end < n; end++) {
            sum += nums[end];

            while (sum >= target) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }

        return ans == n + 1 ? 0 : ans;
    }
};
