class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                maxlen=max(maxlen,i-left+1);
            }
            if(nums[i]==0){
                left=i+1;
            }
        }
        return maxlen;
    }
};