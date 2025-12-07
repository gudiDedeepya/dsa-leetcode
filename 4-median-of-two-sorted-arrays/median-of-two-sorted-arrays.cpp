class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       int n=n1+n2;
       vector<int>merged(n);
       int i=0,j=0,index=0;
       while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            merged[index++]=nums1[i++];
        }
        else{
            merged[index++]=nums2[j++];
        }
       }
       while(i<n1){
        merged[index++]=nums1[i++];
       }
       while(j<n2){
        merged[index++]=nums2[j++];
       }
      if((n%2)==0){
        return (merged[n/2]+merged[n/2-1])/2.0;
      }
     else{
        return merged[n/2];
     }

    }
};