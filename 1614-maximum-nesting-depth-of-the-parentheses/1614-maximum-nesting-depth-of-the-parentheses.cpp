class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                maxCount=max(maxCount,count);
                count--;
            }
            else continue;
        }
        return maxCount;
    }
};