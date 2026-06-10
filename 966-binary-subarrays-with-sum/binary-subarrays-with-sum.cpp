class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int currsum=0;
        int cnt=0;
        for(int num:nums){
            currsum+=num;
            if(mpp.count(currsum-goal)){
                cnt+=mpp[currsum-goal];
            }
            mpp[currsum]++;
        }
        return cnt;
    }
};