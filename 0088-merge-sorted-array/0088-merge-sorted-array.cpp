class Solution {
private:
    void swapifgreater(vector<int>& nums1, vector<int>& nums2,int index1,int index2){
        if(nums1[index1]>nums2[index2]){
            swap(nums1[index1],nums2[index2]);
        }
    }
    
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=(m+n);
        int gap=(len/2)+(len%2);//for ceil
        
        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                // arr1 and arr2
                if(left<m && right>=m){
                    swapifgreater(nums1,nums2,left,right-m);
                }else if(left>=m && (right - m) < n ){ //arr2 and arr2
                    swapifgreater(nums2,nums2,left-m,right-m);
                }else{ //arr1 and arr1
                    swapifgreater(nums1,nums1,left,right);
                }
                left++;
                right++;
            }
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }
        // After merging, nums2 needs to be copied to the remaining part of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};