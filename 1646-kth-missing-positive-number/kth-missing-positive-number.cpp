class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
          vector<int>hash(1001,0);
          for(int i=0;i<arr.size();i++){
             hash[arr[i]]++;
          }
          int cnt=0;
          for(int j=1;j<1001;j++){
            if(hash[j]==0) cnt++;
            if(cnt==k) return j;
          }
          return 1000+k-cnt;
        
    }
};