vector<TreeNode*>ans;
void operation(TreeNode *&root,map<int,int>&mp)
{
    if(root==NULL)
        return;
    operation(root->left,mp);
    operation(root->right,mp);
    if(mp.find(root->val)!=mp.end())
    {
        if(root->left)
            ans.push_back(root->left);
        if(root->right)
            ans.push_back(root->right);
        root=NULL;
        return;
    }
    
}
class Solution 
{
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        ans.clear();
        map<int,int>mp;
        for(auto x:to_delete)
            mp[x]++;
        operation(root,mp);
        if(root!=NULL)
            ans.push_back(root);
        return ans;
    }
};
