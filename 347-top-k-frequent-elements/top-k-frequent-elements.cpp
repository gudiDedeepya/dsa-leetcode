class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (int x : nums)
            freq[x]++;
      
      //int n=freq.size();
      vector<pair<int,int>>fre;

      for(auto it:freq){
        fre.push_back({it.second,it.first});
      }
    sort(fre.begin(),fre.end());
    vector<int>out;
    int n=fre.size();
      for(int i=n-1;i>=n-k;i--){
        out.push_back(fre[i].second);
      }

return out;
       
    }
};