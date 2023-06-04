# Method 1 - Using Monotonic Stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mono;
        unordered_map<int,int> nextGreatest;
        vector<int> ans (nums1.size(),-1);

        for(int i=0; i<nums2.size(); i++){
            int num = nums2[i];

            while(!mono.empty() && mono.top()<num){
                nextGreatest[mono.top()] = num;
                mono.pop();
            }

            mono.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++){
            if(nextGreatest.find(nums1[i])!=nextGreatest.end()){
                ans[i] = nextGreatest[nums1[i]];
            }
        }
        return ans;
    }
};
