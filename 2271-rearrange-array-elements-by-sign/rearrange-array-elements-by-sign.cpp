class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>output(n);
        int even=0;
        int odd=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                output[even]=nums[i];
                even+=2;
            }
            else{
                output[odd]=nums[i];
                odd+=2;
            }
        }
     
        return output;
    }
};