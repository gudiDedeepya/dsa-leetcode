class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
         int prefix_product=1;
         int suffix_product=1;
         int max_product=INT_MIN;
         for(int i=0;i<n;i++){
            if(prefix_product==0)
            prefix_product=1;
            if(suffix_product==0)
            suffix_product=1;
            prefix_product*=nums[i];
            suffix_product*=nums[n-i-1];
            max_product=max(max_product,max(prefix_product,suffix_product));


         }
         return max_product;
    }
};