class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         stack<int>st;
         int n=nums.size();
         vector<int>ans(n,-1);
         for(int i=0;i<2*n;i++){
            int num=nums[i%n];
            while(!st.empty()&&num>nums[st.top()]){
                ans[st.top()]=num;
                st.pop();
            }
            if(i<n)
            st.push(i);
         }
         return ans;
    }
};