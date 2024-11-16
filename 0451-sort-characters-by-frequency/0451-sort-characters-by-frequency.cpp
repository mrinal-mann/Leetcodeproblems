class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> frequency={};
        for(auto c:s){
            frequency[c]++;
        }
        
        vector<vector<char>> bucketData(s.length()+1);
        
        for(auto [ch,fq]:frequency) bucketData[fq].push_back(ch);
        
        string ans="";
        
        for(int i=s.length();i>0;i--){
            for(auto ch:bucketData[i])
                ans.append(i,ch);
        }
        return ans;
        
    }
};