class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26,0);
        vector<bool> inStack(26,false);

        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }

        stack<char> stack;

        for(int i=0; i<s.length();i++){
            if(inStack[s[i]-'a']==false){
                while(!stack.empty()&&stack.top()>char(s[i]) && count[stack.top()-'a']>0){
                        inStack[stack.top()-'a'] = false;
                        stack.pop();
                }
                stack.push(s[i]);
                count[s[i]-'a']--;
                inStack[s[i]-'a'] = true;
            }
            else{
                count[s[i]-'a']--;
            }
        }
        string ans="";
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
}; 
