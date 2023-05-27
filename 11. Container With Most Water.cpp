class Solution {
private:
    int min(int a, int b){
        if(a>b){
            return b;
        }
        else {
            return a;
        }
    }
    int volume(int a, int a1, int b, int b2){
        
        int vol=min(a1,b2)*(b-a);
        return vol;
    }
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int l=height.size()-1;
        int ans=-1;
        while(l>s){
            if(volume(s,height[s],l,height[l])>ans){
                ans=volume(s,height[s],l,height[l]);
            }
            if(height[s]>height[l]){
                l--;
            }
            else{
                s++;
            }
            
        }
        return ans;
    }
};
