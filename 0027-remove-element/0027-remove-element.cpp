
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        // Har element ko check karo
        for (int i = 0; i < nums.size(); i++) {

            // Agar element val ke equal nahi hai
            if (nums[i] != val) {
                nums[k] = nums[i];  // Use aage place karo
                k++;                // Valid elements ki count badhao
            }
        }

        // First k positions mein val ke alawa saare elements hain
        return k;
    }
};
