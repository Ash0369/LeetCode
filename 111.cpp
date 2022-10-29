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
