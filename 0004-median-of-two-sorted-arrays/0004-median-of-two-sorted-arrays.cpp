
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {
        // Binary search hamesha chhote array par karo
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int start = 0;
        int end = m;

        while (start <= end) {
            // nums1 mein kitne elements left part mein honge
            int cut1 = start + (end - start) / 2;

            // Dono arrays ke left part mein total
            // (m + n + 1) / 2 elements hone chahiye
            int cut2 = (m + n + 1) / 2 - cut1;

            // Partition ke left aur right values
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition mil gaya
            if (left1 <= right2 && left2 <= right1) {

                // Total elements odd hain
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Total elements even hain
                return (max(left1, left2) +
                        (double)min(right1, right2)) / 2.0;
            }

            // nums1 ka left part bahut bada hai
            else if (left1 > right2) {
                end = cut1 - 1;
            }

            // nums1 ka left part chhota hai
            else {
                start = cut1 + 1;
            }
        }

        return 0.0;
    }
};
