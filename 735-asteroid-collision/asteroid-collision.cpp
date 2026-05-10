class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
       
        for(int i=0;i<n;i++){
             bool destroyed=false;
            while(!st.empty()&&st.top()>0&&asteroids[i]<0){
                if(abs(asteroids[i])>st.top()) st.pop();
                else if(abs(asteroids[i])==st.top()) {destroyed=true;st.pop(); break;}
                else { destroyed=true;break;}
            }
            if(!destroyed)
            st.push(asteroids[i]);
          
        }
        vector<int> ans(st.size());

        for(int i=st.size()-1;i>=0;i--) {

            ans[i] = st.top();
            st.pop();
        }
    return ans;
    }
};