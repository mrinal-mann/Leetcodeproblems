class Solution {
public:
    int count = 0;

    // Function to merge two halves
    void merge(vector<int>& arr, int l, int m, int r) {
        int* temp = new int[r - l + 1];  // Temporary array
        int left = l;
        int right = m + 1;
        int index = 0;

        // Merging the two halves in sorted order
        while (left <= m && right <= r) {
            if (arr[left] <= arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }

        // Copying remaining elements from left half
        while (left <= m) {
            temp[index++] = arr[left++];
        }

        // Copying remaining elements from right half
        while (right <= r) {
            temp[index++] = arr[right++];
        }

        // Copying the sorted temp array back to the original array
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }

        delete[] temp;  // Freeing up memory
    }

    // Function to count reverse pairs
    void countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
    }

    // Merge sort function
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);        // Sort the left half
        mergeSort(arr, mid + 1, r);    // Sort the right half
        countPairs(arr, l, mid, r);    // Count reverse pairs
        merge(arr, l, mid, r);         // Merge the two halves
    }

    // Main function to calculate reverse pairs
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};
