class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        
        // Start from the last digit and move backward
        for (int i = n - 1; i >= 0; i--) {
            // Check if the digit is odd
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from the start to this odd digit
                return num.substr(0, i + 1);
            }
        }
        
        // If no odd digit is found, return an empty string
        return "";
    }
};
