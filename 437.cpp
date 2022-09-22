class Solution 
{
public:
    long long int ans=0;
    void dfs(TreeNode *root,long long int target)
    {
        if(root==NULL)
            return;
        
        if(root->val==target)
            ans++;
        
        dfs(root->left,target-root->val);
        dfs(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return 0;
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);        
        return ans;
    }
};
