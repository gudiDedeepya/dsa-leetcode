class Solution {
public:
    string removeKdigits(string num, int k) {
        int cnt1=k;
        if(num.size()==k) return "0";
        stack<int>st;
        for(int i=0;i<num.size();i++){
        while(!st.empty()&&st.top()>num[i]&&k>0){
               st.pop();
               k--;
        }
    
        st.push(num[i]);
        }
        while(k>0){
          st.pop();
          k--;
        }
        
       
         string s(st.size(),'x');
        for(int i=st.size()-1;i>=0;i--){
            
            s[i]=st.top();
            st.pop();
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') cnt++;
            else break;

        }
        if(cnt==s.size()) return "0";
        else{
        // int i=0;
        // while(s[i]=='0'&&s.size()>1) i++;

        return s.substr(cnt,s.size()-cnt+1);
        }
    }
};