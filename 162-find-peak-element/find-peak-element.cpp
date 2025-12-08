class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int left=mid-1>=0?nums[mid-1]:INT_MIN;
            int right=mid+1<n?nums[mid+1]:INT_MIN;
            if(nums[mid]>left&&nums[mid]>right){
                return mid;
            }
            else if(nums[mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};