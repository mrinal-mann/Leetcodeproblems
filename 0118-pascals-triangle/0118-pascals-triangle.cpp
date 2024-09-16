class Solution {
public:
    
    vector <int>generateRow(int row){
        long long ans=1;
        vector<int> ansRow;
        ansRow.push_back(1); //it will always be 1
        for(int col=1;col<row;col++){
            ans=ans*(row-col); //formula as the row - col is going through the rows
            ans=ans/(col); // for the denominator 
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
      return ans;  
    }
};