# Method 1 - using O(n) space 

class Solution {
public:
    int minSwaps(string s) {
        map<char,char> compliment;
        compliment['['] = ']';

        stack<char> holder;

        for(int i=0; i<s.size();i++){
            if(holder.empty()){
                holder.push(s[i]);
            }
            else{
                if(holder.top()=='['){
                    if(char(s[i])=='[') {holder.push(s[i]);}
                    else {holder.pop();}
                }
                else{
                    holder.push(s[i]);
                }
            }
        }
        
        int a = (holder.size()/2);

        return (a+1)/2;
        
    }
};

# Method 2 - using O(1) space

class Solution {
public:
    int minSwaps(string s) {
        int l = 0;
        int r = 0;

        for(char a:s){
            if(a=='[') l++;
            else{
                if (l>0) l--;
                else r++;
            }
        }
        return (r+1)/2;
    }
};
