class Solution {
public:
    string reverseWords(string &s) {
        int n = s.length();

        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 2: Reverse each word within the reversed string
        int start = 0, end = 0;
        while (start < n) {
            // Find the start of the word
            while (start < n && s[start] == ' ') start++;
            end = start+1;
            // Find the end of the word
            while (end < n && s[end] != ' ') end++;
            
            // Reverse the word in-place
            reverse(s.begin() + start, s.begin() + end);

            start = end;
        }

        // Step 3: Remove extra spaces
        int i = 0; // Position for the final formatted result
        for (int j = 0; j < n; ++j) {
            if (s[j] != ' ') {  // Non-space character
                if (i != 0) s[i++] = ' ';  // Add single space if it's not the first word
                while (j < n && s[j] != ' ') {
                    s[i++] = s[j++]; //shifting the words
                }
            }
        }
        s.resize(i);  // Resize to the correct length

        return s;
    }
};

