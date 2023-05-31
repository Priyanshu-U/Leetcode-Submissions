class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int size = nums.size();
        if(size==1){
            return nums[0]==target? true:false;
        }

        int low = 0;
        int high = size - 1;

        int mid;

        while(low<=high){
            mid = low + (high - low)/2;

            if(target == nums[mid]){
                return true;
            }

            if(nums[low]==nums[mid]&&nums[high]==nums[mid]){
                low++;
                high--;
            }

            else if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target>nums[mid]&&target<=nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;;
                }
            }
        }
        return false;
    }
};
