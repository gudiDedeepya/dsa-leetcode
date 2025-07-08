class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end());
        int max_length=1;
        int cnt=1;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int x=it;
                cnt=1;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                max_length=max(cnt,max_length);
            }

        }
        return max_length;
    }
};