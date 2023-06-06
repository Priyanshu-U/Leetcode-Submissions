class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int a = abs(arr[1]-arr[0]);
        for(int i=0; i<arr.size()-1; i++){
           if(abs(arr[i]-arr[i+1])!=a){
               return false;
           }
        }
        return true;
    }
};
