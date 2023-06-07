class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();
    vector<int> ans(size,-1);
    stack<int> mono;
    for(int i=0; i<2*size;i++){
        while(!mono.empty() && nums[mono.top()]<nums[i%size]){
            ans[mono.top()] = nums[i%size];
            mono.pop();
        }
        mono.push(i%size);
    }
    return ans;
    }
};
