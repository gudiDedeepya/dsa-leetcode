class Solution {
public:
    string minWindow(string s, string t) {
             int m=s.size();
             int n=t.size();
             unordered_map<char,int>need;
             for(char ch:t){
                need[ch]++;
             }
             int have=0;
             int needcount=need.size();
             int left=0;
             int start=0;
             int minlen=INT_MAX;
             for(int i=0;i<m;i++){
                if(need.count(s[i])){
                 need[s[i]]--;
                if(need[s[i]]==0)
                have++;
                }
                while(have==needcount){
                   if(i-left+1<minlen){
                    minlen=i-left+1;
                    start=left;
                   }
                   if(need.count(s[left])){
                     need[s[left]]++;
                     if( need[s[left]]>0)
                     have--;
                   }
                   left++;

                }

             }
             if(minlen==INT_MAX)
             return "";
             return s.substr(start,minlen);
    }
};