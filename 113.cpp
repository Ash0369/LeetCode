vector<vector<int>>result;
void path(TreeNode *root,int target,vector<int>vec,int sum)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        if(sum+root->val==target)
        {
            vec.push_back(root->val);
            result.push_back(vec);
            vec.pop_back();
        }
        return;
    }
    vec.push_back(root->val);
    path(root->left,target,vec,sum+root->val);
    path(root->right,target,vec,sum+root->val);
    vec.pop_back();
    return;
}
class Solution 
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        result.clear();
        vector<int>vec;
        path(root,targetSum,vec,0);
        return result;
    }
};
