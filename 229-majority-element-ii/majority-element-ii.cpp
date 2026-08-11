class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ls;
        int a,b;
        int cnt_1=0;
        int cnt_2=0;
        for(int i=0;i<n;i++){
            if(cnt_1==0&&nums[i]!=b){
                a=nums[i];
                cnt_1=1;
            }
            else if(cnt_2==0&&nums[i]!=a){
                b=nums[i];
                cnt_2=1;
            }
            else if(a==nums[i])
            cnt_1++;
            else if(b==nums[i])
            cnt_2++;
            else{
            cnt_1--;
            cnt_2--;
            }
        }
        cnt_1=0;
        cnt_2=0;

            for(auto num:nums){
                if(a==num)
                cnt_1++;
                else if(b==num)
                cnt_2++;
            }
        
        if(cnt_1>n/3)
        ls.push_back(a);
        if(cnt_2>n/3)
        ls.push_back(b);
        return ls;
    }
    
};