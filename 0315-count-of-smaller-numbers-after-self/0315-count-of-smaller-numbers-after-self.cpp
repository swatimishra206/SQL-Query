
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> arr;

        // Har element ke saath uska original index store karo
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        vector<pair<int, int>> temp(n);
        mergeSort(arr, temp, ans, 0, n - 1);

        return ans;
    }

private:
    void mergeSort(vector<pair<int, int>>& arr,
                   vector<pair<int, int>>& temp,
                   vector<int>& ans, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, ans, left, mid);
        mergeSort(arr, temp, ans, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int k = left;
        int smaller = 0;

        // Dono sorted halves ko merge karo
        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                temp[k++] = arr[j++];
                smaller++;
            } else {
                // Right half se pehle aaye smaller elements
                // current left element ke answer mein add honge
                ans[arr[i].second] += smaller;
                temp[k++] = arr[i++];
            }
        }

        while (i <= mid) {
            ans[arr[i].second] += smaller;
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Merged array ko original range mein copy karo
        for (int p = left; p <= right; p++) {
            arr[p] = temp[p];
        }
    }
};
