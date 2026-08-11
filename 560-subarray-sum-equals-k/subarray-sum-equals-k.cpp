class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        int cnt=0;
        int n=nums.size();
        mpp.insert({0,1});
        for(int i=0;i<n;i++){
           sum+=nums[i];
           int rem=sum-k;
           if(mpp.find(rem)!=mpp.end()){
            cnt+=mpp[rem];
           }
           if(mpp.find(sum)!=mpp.end()) mpp[sum]++;
           else mpp.insert({sum,1});
        }
        return cnt;
    }

};