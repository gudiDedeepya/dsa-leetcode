class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
         int len=0;
         int n=s.length();
         int st=0;
         if(n==0)
         return 0;
         for(int i=0;i<n;i++){
            if(mpp.count(s[i])){
          
           st=max(st,mpp[s[i]]+1);
            }
            len=max(len,(i-st+1));
            mpp[s[i]]=i;
        
         }
         return len;
    }
};