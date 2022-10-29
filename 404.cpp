void dfs(TreeNode *root,int parent,int &sum)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL && parent==1)
    {
        sum+=root->val;
        return;
    }
    dfs(root->left,1,sum);
    dfs(root->right,0,sum);
}
class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum=0;
        dfs(root,0,sum);
        return sum;
    }
};
