class Solution {
public:
int caluclateSum(vector<int>&nums,int mid,int k){
    int suba=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
      if(nums[i]+sum<=mid){
        sum+=nums[i];
      }
      else{
        suba++;
        sum=nums[i];
      }
    }
    if(suba<=k)return true;
    return false;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(caluclateSum(nums,mid,k)){
            high=mid-1;
            }
            else
            low=mid+1;
 }
     return low;
    }
};