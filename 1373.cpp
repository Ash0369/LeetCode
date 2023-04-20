#define ll long long
ll int ans;
ll int inf=-1*1e18;
vector<ll int>dfs(TreeNode *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return {root->val,root->val,root->val};
    }
    if(root->left!=NULL && root->right!=NULL)
    {
        auto u=dfs(root->left);
        auto v=dfs(root->right);
        ans=max(ans,max(u[0],v[0]));
        if(u[0]==inf || v[0]==inf)
        {
            return {inf,0,0};
        }
        if(root->val>u[2] && root->val<v[1])
        {
            return {u[0]+v[0]+root->val,u[1],v[2]};
        }
        return {inf,0,0};
    }
    if(root->left!=NULL)
    {
        auto u=dfs(root->left);
        ans=max(ans,u[0]);
        if(u[0]==inf)
        {
            return {inf,0,0};
        }
        if(root->val>u[2])
        {
            return {u[0]+root->val,u[1],root->val};
        }
        return {inf,0,0};
    }
    auto v=dfs(root->right);
    if(v[0]==inf)
    {
        return {inf,0,0};
    }
    ans=max(ans,v[0]);
    if(root->val<v[1])
    {
        return {v[0]+root->val,root->val,v[2]};
    }
    return {inf,0,0};
}
class Solution 
{
public:
    int maxSumBST(TreeNode* root) 
    {
        ans=0;
        ans=max(ans,dfs(root)[0]);
        return ans;
    }
};
