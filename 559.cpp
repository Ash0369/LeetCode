int dfs(Node *root)
{
    if(root->children.size()==0)
        return 1;
    int mx_depth=0;
    for(auto x:root->children)
    {
        mx_depth=max(mx_depth,dfs(x));
    }
    return 1+mx_depth;
}
class Solution 
{
public:
    int maxDepth(Node* root) 
    {
        if(root==NULL)
            return 0;
        return dfs(root);
    }
};
