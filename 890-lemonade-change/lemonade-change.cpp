class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int bill1=0;
        int bill2=0;
        int bill3=0;


        for(int i=0;i<n;i++){
            if(bills[i]==10){
            if(bill1>0){
            bill1--;
            bill2++;
            }
            else 
            return false;
            }
            else if(bills[i]==20){
            if(bill1>0&&bill2>0){
                bill1--;
                bill2--;
                bill3++;
            }
            else if(bill1>=3)
            {
                bill1-=3;
                bill3++;
            }
            else 
            return false;
            }
            else{
                bill1++;
            }

        }
        return true;
    }
};