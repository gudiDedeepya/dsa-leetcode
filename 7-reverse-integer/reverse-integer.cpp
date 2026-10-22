class Solution {
public:
    int reverse(int x) {
        if(x==INT_MAX||x==INT_MIN) return 0;
        long long num=0;
        int digit=0;
        int sign=1;
        if(x<0){
            sign=-1;
            x=-1*x;
        }
        while(x>0){
            digit=x%10;
            if(num*10+digit>=INT_MAX) return 0;
            num=num*10+digit;
            x=x/10;

        }
        return sign*int(num);
    }
};