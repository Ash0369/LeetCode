//Method-1 : BFS Algorthim

class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        
        vector<int>result;
        
        while(!q.empty())
        {
            int k=q.size();
            int val=INT_MIN;
            for(int i=0;i<k;i++)
            {
                auto x=q.front();
                q.pop();
                val=max(x->val,val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            result.push_back(val);
        }
        return result;
    }
};


//Method-2 : DFS Algorthim

void dfs(TreeNode *root,vector<int>&result,int level)
{
    if(root==NULL)
        return;
    if(result.size()<=level)
        result.push_back(root->val);
    result[level]=max(result[level],root->val);
    
    dfs(root->left,result,level+1);
    dfs(root->right,result,level+1);
}
class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int>result;
        dfs(root,result,0);
        return result;
    }
};
