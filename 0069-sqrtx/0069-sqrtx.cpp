
class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // mid * mid ki jagah division use karo
            // taaki integer overflow na ho
            if (mid <= x / (mid == 0 ? 1 : mid)) {
                ans = mid;       // mid possible answer hai
                start = mid + 1; // aur bada answer search karo
            } else {
                end = mid - 1;   // mid bada hai, left mein jao
            }
        }

        return ans;
    }
};
