#include <unordered_map>
#include <string>
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romannumber={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int total=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i<n-1 && romannumber[s[i]]<romannumber[s[i+1]]){
                total-=romannumber[s[i]];
            }else{
                total+=romannumber[s[i]];
            }
        }
        return total;
    }
    
};