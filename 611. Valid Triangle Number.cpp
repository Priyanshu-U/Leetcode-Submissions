# Method 1 - Loop and 2 Pointer

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end());

        int sol =0;

        for(int c=size-1; c>=2;c--){
            int a = 0; int b = c-1;

            while(a<b){
                if(nums[a]+nums[b]<=nums[c]){
                    a++;
                }
                else{
                    sol += (b-a);
                    b--;
                }
            }
        }
        return sol;
    }
};
