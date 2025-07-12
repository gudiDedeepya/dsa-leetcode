class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum=INT_MAX;
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[low]<=nums[mid]){
                minimum=min(nums[low],minimum);
                 low=mid+1;

            }
            else{
                minimum=min(nums[mid],minimum);
                high=mid-1;
            }
        }
        return minimum;

    }
};