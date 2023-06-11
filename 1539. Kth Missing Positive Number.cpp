# Method 1 - Greedy with Binary Search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size()-1;

    int mid;
    int ans;

    while(low<=high){
        mid = low + (high - low)/2;

        if(arr[mid]-(mid+1)<k){
            ans = mid+1;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans+k;

    }
};
