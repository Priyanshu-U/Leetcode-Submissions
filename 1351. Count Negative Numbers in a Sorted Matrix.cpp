class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i=0;i<m;i++ ){
            
            int l = 0;
            int h = n-1;
            int mid = l + ( h - l )/2;

            int first_occur = n;

            while(l<=h){
                if(grid[i][mid]<0){
                    first_occur = mid;
                    h = mid-1;
                }
                else{
                    l = mid+1;
                }
                mid = l + (h-l)/2;
            }
            ans+=n-first_occur;
        }
        return ans;
    }
};
