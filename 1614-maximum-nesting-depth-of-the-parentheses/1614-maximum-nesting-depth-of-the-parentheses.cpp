class Solution {
public:
    int maxDepth(std::string s) {
        int count = 0;
        int maxCount = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
                maxCount = std::max(maxCount, count); // Update max depth
            } else if (c == ')') {
                count--;
            }
        }
        return maxCount;
    }
};