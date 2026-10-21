
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: Array ko sort karo
        sort(nums.begin(), nums.end());

        // Pehla element choose karo
        for (int i = 0; i < n - 3; i++) {

            // Duplicate quadruplets avoid karo
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Doosra element choose karo
            for (int j = i + 1; j < n - 2; j++) {

                // j ke duplicates skip karo
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Two pointers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // long long overflow se bachne mein help karta hai
                    long long sum = (long long)nums[i] + nums[j]
                                  + nums[left] + nums[right];

                    if (sum == target) {
                        // Valid quadruplet mil gaya
                        ans.push_back({
                            nums[i], nums[j], nums[left], nums[right]
                        });

                        left++;
                        right--;

                        // left ke duplicate values skip karo
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }

                        // right ke duplicate values skip karo
                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                    else if (sum < target) {
                        // Sum chhota hai, left pointer aage badhao
                        left++;
                    }
                    else {
                        // Sum bada hai, right pointer peeche lao
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
