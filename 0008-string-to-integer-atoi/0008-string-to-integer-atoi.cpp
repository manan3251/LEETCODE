class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int sign = 1;
        long long num = 0;

        while ( i < s.length() && s[i] == ' ' ) {
            i++;
        }

        if ( i <s.length() && s[i] == '-' ) {
            sign = -1;
            i++;
        }
        else if ( i < s.length() && s[i] == '+' ) {
            sign = 1;
            i++;
        }

        while ( i < s.length() && s[i] >= '0' && s[i] <= '9' ) {
            int digit = s[i] - '0';

            if ( num > INT_MAX / 10 || 
            (num == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8 ))) {
                return ( sign == 1 ) ? INT_MAX : INT_MIN;
            }
            num = num * 10 + digit;

            i++;
        }
        return (int)(num*sign);
        
    }
};