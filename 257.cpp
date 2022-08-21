void check(TreeNode *root,vector<string>&res,string temp)
{
    if(root->left==NULL && root->right==NULL)
    {
        res.push_back(temp);
    }
    if(root->left)
    {
        string a=temp+"->"+to_string(root->left->val);
        check(root->left,res,a);
    }
    if(root->right)
    {
        temp=temp+"->"+to_string(root->right->val);
        check(root->right,res,temp);
    }
}
class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        vector<string>res;
        string temp=to_string(root->val);
        check(root,res,temp);
        return res;
    }
};
