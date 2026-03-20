class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int odd_cnt=0;
        int st=0;
        for(int i=0;i<n;i++){
             if(nums[i]%2)
             odd_cnt++;
          
             while(odd_cnt>k){
             if(nums[st]%2)
             odd_cnt--;
             st++;
             }
                if(odd_cnt==k){
                 int temp=st;
                 for(temp=st;temp<i;temp++){
                    if(nums[temp]%2==1)
                    break;
                    else
                    cnt++;
                 }
             cnt++;
                }
        }
        return cnt;
    }
};