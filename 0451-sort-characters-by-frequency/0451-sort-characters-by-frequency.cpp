class Solution {
public:
    std::string frequencySort(std::string s) {
        // Step 1: Count the frequency of each character
        std::unordered_map<char, int> frequency;
        for (char c : s) {
            frequency[c]++;
        }

        // Step 2: Create buckets, where the index represents the frequency
        std::vector<std::vector<char>> bucketData(s.length() + 1);
        for (const auto& [ch, fq] : frequency) {
            bucketData[fq].push_back(ch);
        }

        // Step 3: Build the result string from the buckets
        std::string ans = "";
        for (int i = s.length(); i > 0; i--) { // Iterate from high to low frequency
            for (char ch : bucketData[i]) {
                ans.append(i, ch); // Append 'i' copies of character 'ch'
            }
        }

        return ans;
    }
};