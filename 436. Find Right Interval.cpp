class Solution {
public:
    int linSearch( int target, vector<int>& list){
        int size = list.size();
        int ans = -1;
        for(int i=0; i<size; i++){
            if(list[i]==target){
                ans = i;
            }
        }
        return ans;
    } 

    int findVal(int target, vector<int>& list){
        int l = 0;
        int size = list.size();
        int h = size-1;

        int mid = l + (h-l)/2;

        int ans = -1;

        while(l<=h){
            if (list[mid] >= target){
                ans = mid;
                h = mid - 1;
            }

            else{
                l = mid + 1;
            }
             
            mid = l + (h-l)/2;
        }
        return ans;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        vector<int> val1;
        vector<int> val1_sorted;

        int size = intervals.size();

        for(int i=0; i<size; i++){
            val1.push_back(intervals[i][0]);
        }

        val1_sorted = val1;
        sort(val1_sorted.begin(),val1_sorted.end());

        for(int i=0; i<size; i++){
            int valIndex =  findVal(intervals[i][1], val1_sorted);
            if(valIndex == -1){
                ans.push_back(-1);
            }
            else{
                ans.push_back(linSearch(val1_sorted[valIndex],val1));
            }

        }
        return ans;
    }
};
