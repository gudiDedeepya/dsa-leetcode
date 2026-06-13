class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>d;
        vector<int>out;
        for(int i=0;i<n;i++){
               while(!d.empty()&&d.front()<=i-k){
                d.pop_front();
            }
          
            while(!d.empty()&&nums[d.back()]<=nums[i]){
                d.pop_back();
            }
         
            d.push_back(i);
              if(i>=k-1){
                out.push_back(nums[d.front()]);
            }


        }
        return out;
    }
};