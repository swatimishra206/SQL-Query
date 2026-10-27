class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        // Array ko sort karna zaroori hai
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // First number fix karenge
        for (int i = 0; i < n - 2; i++) {

            // Duplicate first number skip karo
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    // Triplet mil gaya
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Duplicate left values skip karo
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Duplicate right values skip karo
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                else if (sum < 0) {
                    // Sum chhota hai, bada number chahiye
                    left++;
                }

                else {
                    // Sum bada hai, chhota number chahiye
                    right--;
                }
            }
        }

        return ans;
    }
};