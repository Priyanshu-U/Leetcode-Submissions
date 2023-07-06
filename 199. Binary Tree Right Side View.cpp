# Method - 1 Creating map for storing data per height

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {


        vector<int> ans;

        if(!root){
            return ans;
        }
       
        map<int,int> LastNode;
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0,root));

        while(!q.empty()){
            TreeNode* temp = q.front().second;
            int level = q.front().first;
            q.pop();

            if(LastNode.find(level)==LastNode.end()){
                LastNode[level] = temp->val;
            } 

            if(temp->right) q.push(make_pair(level+1,temp->right));
            if(temp->left) q.push(make_pair(level+1,temp->left));

        }
        for(auto i: LastNode){
            ans.push_back(i.second);
        }

        return ans;
    }
};

# Method - 2 Using External Variable to store value of the last non numm value in each queue sub section.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;

        if(root == nullptr)
        {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        int current = 0;

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node)
            {
                current = node->val;

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            else
            {
                result.push_back(current);

                if(!q.empty())
                {
                    q.push(nullptr);
                }
            }
        }

        return result;    
    }
};
