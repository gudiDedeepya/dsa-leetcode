class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int index=nums.size();
        int mid;
        while(low<=high){
          mid=(low+high)/2;
          if(nums[mid]==target){
          return mid;
          }
          else if(nums[mid]>target){
          high=mid-1;
          index=mid;
          }
          else
          low=mid+1;
        }
        return index;
    }
};