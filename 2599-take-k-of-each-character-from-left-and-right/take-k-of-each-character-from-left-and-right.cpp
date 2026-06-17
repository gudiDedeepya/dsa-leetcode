class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>totalch(3,0);
        int n=s.size();
        for(int i=0;i<n;i++) totalch[s[i]-'a']++;
        vector<int>infreq(3,0);
        if(totalch[0] < k ||
           totalch[1] < k ||
           totalch[2] < k)
            return -1;

        int l=0;
        int ans=0;
        for(int i=0;i<n;i++){
            infreq[s[i]-'a']++;
            while(infreq[0]>totalch[0]-k||infreq[1]>totalch[1]-k||infreq[2]>totalch[2]-k){
                infreq[s[l]-'a']--;
                 l++;
            }
            ans=max(ans,i-l+1);
        }
        return n-ans;
    }
};