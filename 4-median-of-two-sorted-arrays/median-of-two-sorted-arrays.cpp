class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       int n=n1+n2;
       int ind2=n/2;
       int ind1=ind2-1;
       int i=0,j=0,cnt=-1;
       int ind1el=-1;
       int ind2el=-1;
       while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
                        cnt++;

            if(cnt==ind1)ind1el=nums1[i];
            if(cnt==ind2)ind2el=nums1[i];
            i++;

        }
        else{
                        cnt++;

            if(cnt==ind1)ind1el=nums2[j];
            if(cnt==ind2)ind2el=nums2[j];
            
            j++;
        }
       }
       while(i<n1){
                    cnt++;

             if(cnt==ind1)ind1el=nums1[i];
            if(cnt==ind2)ind2el=nums1[i];
    
            i++;
       }
       while(j<n2){
                    cnt++;

           if(cnt==ind1)ind1el=nums2[j];
            if(cnt==ind2)ind2el=nums2[j];
        
            j++;
       }
      if((n%2)==0){
        return (ind1el+ind2el)/2.0;
      }
     else{
        return ind2el;
     }

    }
};