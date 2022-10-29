//Method-1 : With extra space


int maxf=0;
void dfs(TreeNode *root,map<int,int>&mp)
{
    if(root==NULL)
        return;
    mp[root->val]++;
    maxf=max(maxf,mp[root->val]);
    dfs(root->left,mp);
    dfs(root->right,mp);
}
class Solution 
{
public:
    vector<int> findMode(TreeNode* root) 
    {
        map<int,int>mp;
        vector<int>ans;
        maxf=0;
        dfs(root,mp);
        for(auto x:mp)
        {
            if(x.second==maxf)
                ans.push_back(x.first);
        }
        return ans;
    }
};
