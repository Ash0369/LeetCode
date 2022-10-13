class Solution 
{
public:
    vector<int>res;
    void iterate(TreeNode *root)
    {
        if(root==NULL)
            return;
        res.push_back(root->val);
        iterate(root->left);
        iterate(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        iterate(root1);
        iterate(root2);
        sort(res.begin(),res.end());
        return res;
    }
};
