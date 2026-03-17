class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        vector<int>freq(26,0);
        int maxfreq=0;
        int st=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
             freq[s[i]-'A']++;
             maxfreq=max(maxfreq,freq[s[i]-'A']);
             while(((i-st+1)-maxfreq)>k){
                freq[s[st]-'A']--;
                st++;
                }
                            maxLen = max(maxLen, i-st + 1);
        }

        return maxLen;

    }

};