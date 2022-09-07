string construct(TreeNode *root)
{
    if(root==NULL)
    {
        return "";
    }
    string s;
    string t;
    t=to_string(root->val);
    s=s+t;
    if(root->left)
    {
        s.push_back('(');
        s=s+construct(root->left);
        s.push_back(')');
    }
    if(!root->left && root->right)
    {
        s=s+"()";
    }
    if(root->right)
    {
        s.push_back('(');
        s=s+construct(root->right);
        s.push_back(')');
    }
    return s;
}
class Solution 
{
public:
    string tree2str(TreeNode* root) 
    {
        return construct(root);
    }
};
