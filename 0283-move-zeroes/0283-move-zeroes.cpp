class Solution {
public:

    void moveZeroes(vector<int>& nums) {
        int j=-1; //for finding the j position ie the 0
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        
        if(j==-1) return; //no non zero numbers
        
        
        // for the swap of the number using two pointer approch 
        for(int i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;
            }
        }
        
        
        
    }
};