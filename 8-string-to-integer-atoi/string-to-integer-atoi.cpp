class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        long long num = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Check sign
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Read digits
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. Clamp if overflow
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return num * sign;
    }
};
