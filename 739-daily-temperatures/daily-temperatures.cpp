class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>output(n);
        stack<pair<int,int>>st;
        int nge=-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top().first<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                output[i]=0;
                st.push({temperatures[i], i});
            }
            else{
                output[i]=st.top().second-i;
                st.push({temperatures[i], i});
            }
        }
        return output;
    }
};