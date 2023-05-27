class Solution {
public:
    int firstOccur(vector<int> &nums, int target){
        int size = nums.size();

        int low = 0;
        int high = size - 1;

        int mid = low + (high - low)/2;

        int ans = -1; 

        while(low<=high){
            
            if(target == nums[mid]){
                ans = mid;
                high = mid-1;
            }

            else if(target > nums[mid]){
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }

            mid = low + (high - low)/2;
        }
        return ans;
    }

     int lastOccur(vector<int> &nums, int target){
        int size = nums.size();

        int low = 0;
        int high = size - 1;

        int mid = low + (high - low)/2;

        int ans = - 1;

        while(low<=high){
            
            if(target == nums[mid]){
                ans = mid;
                low = mid + 1;
            }

            else if (target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1 ;
            }

            mid = low + (high - low)/2;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        ans.push_back(firstOccur(nums,target));
        ans.push_back(lastOccur(nums,target));
        return ans;
    }
};
