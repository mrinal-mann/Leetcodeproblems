class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; // Return false if lengths don't match
        
        sort(s.begin(), s.end()); // Sort string s
        sort(t.begin(), t.end()); // Sort string t
        
        return s == t; // Compare sorted strings
    }
};
