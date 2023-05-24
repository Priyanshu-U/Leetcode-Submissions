class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int size = nums.size();
        int high = size-1;

        int mid = low + (high - low)/2;

        while (low <= high){
            if (nums[mid] == target){
                return mid;
            }

            else if (target > nums[mid]){
                low = mid + 1;
            }

            else {
                high = mid -1;
            }
            mid = low + (high - low)/2;
        }
        return -1;
    }
};
