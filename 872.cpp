void trace(TreeNode *root,vector<int>&vec)
{
    if(root->left==NULL && root->right==NULL)
    {
        vec.push_back(root->val);
        return;
    }
    
    if(root->left)
        trace(root->left,vec);
    if(root->right)
        trace(root->right,vec);
}
class Solution 
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>vec1;
        vector<int>vec2;
        trace(root1,vec1);
        trace(root2,vec2);
        
        if(vec1==vec2)
            return true;
        return false;
            
    }
};
