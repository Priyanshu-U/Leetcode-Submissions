class Solution {
public:
    int findPivot(vector<int>& nums){
        int low = 0;
        int size = nums.size();
        int high = size - 1;

        int mid;
        int ans = -1;
        int start = nums[0];

        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid+1]){
                ans = mid;
                break;
            }
            else if(nums[mid] >= start){
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return ans;
    }

    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int pivot = findPivot(nums);

        if (pivot == -1) {
            return binarySearch(nums, target, 0, nums.size() - 1);
        }

        if (nums[pivot] == target) {
            return pivot;
        }

        int index1 = binarySearch(nums, target, 0, pivot - 1);
        int index2 = binarySearch(nums, target, pivot + 1, nums.size() - 1);

        if (index1 != -1) {
            return index1;
        } 
        else if (index2 != -1) {
            return index2;
        } 
        else {
            return -1;
        }
    }
};
