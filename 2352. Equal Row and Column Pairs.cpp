# Method 1 - Optimised O(N3)

class Solution {
public:
    int equalPairs(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;

        for( int i = 0 ; i < rows ; i++ ){
            for( int j = 0 ; j < cols ; j++ ){
                if(matrix[i][0]!=matrix[0][j]){
                    continue;
                }
                else{
                    for(int k = 0; k<rows ;k++){
                        if(matrix[i][k]!=matrix[k][j]){
                            break;
                        }
                        if(k==rows-1)ans++;
                    }
                }
            }
        }
        return ans;
    }
};
