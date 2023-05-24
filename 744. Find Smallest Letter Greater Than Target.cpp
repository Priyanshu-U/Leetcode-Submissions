class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        if(target == 'z'){
            return letters[0];
        }

        int low = 0;
        int size = letters.size();
        int high = size - 1;

        int mid = low + (high - low)/2;

        int ans = letters[0];

        while( low <= high ){
            if (letters[mid] > target){
                ans = letters[mid];
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            mid = low + (high - low)/2;
        }
        return ans;
    }
};
