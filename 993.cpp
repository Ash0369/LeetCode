pair<int,int> dfs(TreeNode *root,int &val,int depth,TreeNode *parent)
{
    if(root==NULL)
        return {-1,-1};
    if(root->val==val)
    {
        return {depth,parent->val};
    }
    auto l=dfs(root->left,val,depth+1,root);
    if(l.first!=-1)
        return l;
    return dfs(root->right,val,depth+1,root);
}
class Solution 
{
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {

        auto d1=dfs(root,x,0,root);
        auto d2=dfs(root,y,0,root);
        
        return d1.first==d2.first && d1.second!=d2.second;
    }
};
