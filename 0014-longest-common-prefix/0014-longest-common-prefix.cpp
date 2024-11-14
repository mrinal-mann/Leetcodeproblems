class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Return empty if there are no strings
        
        // Start with the first string as the initial prefix
        string prefix = strs[0];
        
        // Compare the prefix with each string in the array
        for (int i = 1; i < strs.size(); i++) {
            // Reduce the prefix length until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";  // Return empty if no common prefix
            }
        }
        
        return prefix;
    }
};
