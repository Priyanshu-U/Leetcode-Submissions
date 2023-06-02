class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> doubles;
        for(int i=0;i<nums.size();i++){
            if(doubles.count(nums[i])==0){
                doubles.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;

    }
};
