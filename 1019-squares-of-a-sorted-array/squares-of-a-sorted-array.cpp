class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=n-1;
        vector<int>out(n);
        int i=n-1;

        while(left<=right){
            int sq1=nums[left]*nums[left];
            int sq2=nums[right]*nums[right];

            if(sq1<sq2){
                out[i--]=sq2;
                right--;
            }
            else{
                out[i--]=sq1;
                left++;
            }
        }
        return out;
    }
};