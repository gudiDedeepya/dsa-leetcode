class Solution {
public:
    int maxPower(string s) {
        int max_len=1;
        int len=1;
        int i=1;
        int n=s.size();
        char ch=s[0];

        while(i<n){
            while(i<n&&ch==s[i]) {len++; i++;
            }
            max_len=max(max_len,len);
            len=1;
            ch=s[i];
            i++;
        }
        return max_len;
    }
};