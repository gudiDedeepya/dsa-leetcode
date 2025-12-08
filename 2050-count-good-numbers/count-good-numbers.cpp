class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp &1)   // if exponent is odd
                result = (result * base) % MOD;

            base = (base * base) % MOD;  // square the base
            exp >>=1;  // divide exponent by 2
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  // positions with 5 choices
        long long odd  = n / 2;        // positions with 4 choices

        long long p1 = modPow(5, even);  // compute 5^even % MOD
        long long p2 = modPow(4, odd);   // compute 4^odd % MOD

        return (p1 * p2) % MOD;
    }
};
