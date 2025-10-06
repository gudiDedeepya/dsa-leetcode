class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Cast to long long before taking abs to avoid UB
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            ans += multiple;
        }

        // Apply correct sign
        bool sameSign = (dividend > 0) == (divisor > 0);
        return sameSign ? ans : -ans;
    }
};
