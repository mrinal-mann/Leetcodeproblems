class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if lengths are different
        if (s.length() != goal.length()) return false;

        // Concatenate s with itself
        string doubled = s + s;

        // Check manually if goal is a substring of doubled
        for (int i = 0; i <= doubled.length() - goal.length(); ++i) {
            if (doubled.substr(i, goal.length()) == goal) {
                return true;
            }
        }
        return false;
    }
};
