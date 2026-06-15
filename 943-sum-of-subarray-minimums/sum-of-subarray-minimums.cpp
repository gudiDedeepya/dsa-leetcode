class Solution {
public:
vector<int> nse(vector<int>&arr){
    vector<int>output(arr.size(),-1);
    for(int i=0;i<arr.size();i++) output[i]=arr.size()-i;
    stack<int>st;
    for(int i=0;i<arr.size();i++){
         while(!st.empty()&&arr[st.top()]>=arr[i]){
                output[st.top()]=i-st.top();
                st.pop();
        }
         st.push(i);
        }

       return output;

}

vector<int> pse(vector<int>&arr){
    vector<int>output(arr.size(),-1);
    for(int i=0;i<arr.size();i++) output[i]=i+1;
    stack<int>st;
    for(int i=0;i<arr.size();i++){
          while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
         if(!st.empty()&&arr[st.top()]<=arr[i]){
                output[i]=i-st.top();
        }
      
         st.push(i);
        }

       return output;

}



    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        long long sum=0;
        vector<int>left=pse(arr);
        vector<int>right=nse(arr);
        for(int i=0;i<n;i++){
            sum=sum+(1LL*arr[i]*left[i]*right[i])%mod;

        }
        return sum%mod;
    }
};