class Solution {
public:
    bool checkValidString(string s) {
        int cnt1=0;
        int cnt2=0;
        for(char c:s){
            if(c=='(') {
                cnt1++;
                cnt2++;
            }
            else if(c==')') {
                cnt1--;
                cnt2--;
            }
            else if(c=='*') {
                cnt1++;
                cnt2--;
            }
            if(cnt1<0) return false;
            if(cnt2<0) cnt2=0;
        }
        if(cnt2==0) return true;
        //else if(cnt>0&&cnt-cnt2==0||cnt<0&&cnt+cnt2==0) return true;
        return false;
    }
};