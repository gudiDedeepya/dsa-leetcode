class Solution {
public:
int subarraysWithKDist(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int l=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
          cnt+=i-l+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKDist(nums,k)-subarraysWithKDist(nums,k-1);
    }
};