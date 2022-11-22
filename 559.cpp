int dfs(Node *root)
{
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
