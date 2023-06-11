# Method 1 - Math and Binary Search
class Solution {
public:
    long sumNM(long peak, long dist){
        return ((peak*(peak+1)/2) - ((peak-dist)*(peak-dist+1)/2));
    }

    int maxValue(int n, int index, int maxSum) {
        

        maxSum-=n;
        int low = 1;
        int high = maxSum;
        int mid;

        int ans=0;
        long sum;

        while(low<=high){
           mid = low + (high-low)/2;
           sum = sumNM(mid-1,min(index,mid-1))+sumNM(mid-1,min((n-index-1),mid-1))+mid;

           if(sum <= maxSum){
               ans = mid;
               low = mid + 1;
           }
           else{
               high = mid - 1;
           }
        }

        return ans+1;
    }
};
