//Method-1 : DFS

void dfs(TreeNode *root,int &ans,int curr)
{
    if(root->left==NULL && root->right==NULL)
    {
        ans=min(ans,curr);
        return;
    }
    if(root->left)
        dfs(root->left,ans,curr+1);
    if(root->right)
        dfs(root->right,ans,curr+1);
}
class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int ans=INT_MAX;
        dfs(root,ans,1);
        return ans;
    }
};


//Method-2 : BFS

class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int curr=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                if(node->left==NULL && node->right==NULL)
                {
                    return curr;
                }
            }
            curr++;
        }
        
        return 0;
    }
};
