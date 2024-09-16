class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1; // figure the break point a[i]<a[i+1]
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){  //edge case is the index is -1
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>index;i--){  // swap the breakpoint element with the smallest element close to the breakpoint
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end()); //reverse the remaining elements
        return;
        
    }
};