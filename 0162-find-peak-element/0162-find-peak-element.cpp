class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=nums.size()-1;
        int ans=n;

        while(start<end){
            int mid=start+(end-start)/2;

            if(nums[mid]<nums[mid+1]){
                ans=mid+1;
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid;
            }
        }
        return start;
        
    }
};