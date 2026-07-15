class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string ans="";
        if((numerator<0)^(denominator<0)) ans+="-";

        long long num=llabs((long long)numerator);
        long long den=llabs((long long)denominator);

        long long rem=INT_MAX;
      //  long long q=0;

            ans+=to_string(num/den);

            rem=num%den;
            if(rem==0) return ans;

            ans+=".";
            unordered_map<long long,int>mpp;

            while(rem!=0){
                if(mpp.find(rem)!=mpp.end()){
                    ans.insert(mpp[rem],"(");
                    ans+=")";
                    break;
                }
                mpp[rem]=ans.size();
                rem*=10;
                ans+=to_string(rem/den);
                rem%=den;


            }
            return ans;







    }
};