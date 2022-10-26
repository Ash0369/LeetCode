//Method-1 : DFS

void dfs(TreeNode*left,TreeNode *right,int level)
{
    if(left==NULL && right==NULL)
        return;
    if(level%2==0)
    {
        swap(left->val,right->val);
    }
    dfs(left->left,right->right,level+1);
    dfs(left->right,right->left,level+1);
}
class Solution 
{
public:
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        dfs(root->left,root->right,0);
        return root;
    }
};


//Method-2 : BFS


class Solution 
{
public:
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(!root)
            return root;
        
        queue<TreeNode*> q;
        vector<int> values;
        q.push(root);
        int level=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int>temp;
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front(); q.pop();
                
                if(level%2==1)
                    node->val = values[sz-i-1];
                
                if(node->left)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right) 
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
                
            }
            values = temp;
            level++;
        }
        return root;
    }
};
