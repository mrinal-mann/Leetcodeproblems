#include <climits>
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int result = 0;
        int i = 0;
        int sign = 1;
        
        // Ignore leading spaces
        while (i < n && s[i] == ' ') i++;
        
        // Check sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow before updating result
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};
