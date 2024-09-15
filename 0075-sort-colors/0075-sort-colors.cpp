class Solution {
public:
    
    void mySwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
   }
    
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                mySwap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                mySwap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};