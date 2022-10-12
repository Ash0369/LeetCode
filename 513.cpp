//Method1 : DFS

#define ll long long 
class Solution 
{
public:
    
    int mx_level=0;
    ll int a=INT_MIN+5;
    void dfs(TreeNode *root,int level,vector<ll int>&data)
    {
        if(root==NULL)
            return;
        mx_level=max(mx_level,level);
        if(data[level]==a)
        {
            data[level]=root->val;
        }
        dfs(root->left,level+1,data);
        dfs(root->right,level+1,data);
    }
    int findBottomLeftValue(TreeNode* root) 
    {
        
        vector<ll int>data(10000,a);
        dfs(root,0,data);
        return data[mx_level];
    }
};
