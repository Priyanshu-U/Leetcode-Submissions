# Method 1 - Iterative and Binary Search
# Time Complexity O(n*log(m))
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


# Method 2 - 2 Pointer
# Time Complexity O(m+n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        int r = rows - 1;
        int c = 0;

        int ans = 0;
        while(r>=0 && c<columns){
            if(grid[r][c]<0){
                ans += columns - c;
                r--;
            }
            else{
                c++;
            }
        }
        return ans;
    }
};
