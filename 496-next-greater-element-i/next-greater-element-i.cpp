class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
           
             int n1=nums1.size();
             int n2=nums2.size();
             vector<int>out(n1,-1);
             for(int i=0;i<n1;i++){
                for(int j=0;j<n2;j++){
                    if(nums2[j]==nums1[i]){
                      for(int k=j;k<n2;k++){
                        if(nums2[k]>nums2[j]){
                        out[i]=nums2[k];
                        break;
                        }
                      }

                    }
                    
                }
                

             }
             return out;
    }
};