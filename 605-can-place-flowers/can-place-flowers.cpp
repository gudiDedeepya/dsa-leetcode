class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(i<flowerbed.size()&&n>0){
            if(flowerbed[i]==1){
                i+=2;
            }
            else {
               int left = i-1>=0?flowerbed[i-1]:0;

              int right =i+1<flowerbed.size()?flowerbed[i+1]:0;
                if(left==0&&right==0){
                    n--;
                    flowerbed[i]=1;
                    i+=2;
                }
                else{
                    i++;
                }
            }
        }
        return n==0?true:false;
    }
};