void flip(TreeNode *&root)
{
    TreeNode *temp=root->left;
    root->left=root->right;
    root->right=temp;
}

void clr_vector(vector<int>&vec)
{
    vec.clear();
    vec.push_back(-1);
}
void check(TreeNode *root,int &index,vector<int>&ans,vector<int>&voyage)
{
    if(root->left)
    {
        index=index+1;
        if(root->left->val!=voyage[index])
        {
            flip(root);
            ans.push_back(root->val);
            if(!root->left || root->left->val!=voyage[index])
            {
                clr_vector(ans);
                return;
            }
        }
        
        check(root->left,index,ans,voyage);
    } 
    if(root->right)
    {
        index=index+1;
        if(root->right->val!=voyage[index])
        {
            clr_vector(ans);
            return;
        }
        check(root->right,index,ans,voyage);
    }
    
}
class Solution 
{
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) 
    {
        if(root->val!=voyage[0])
            return {-1};
        vector<int>ans;
        int index=0;
        check(root,index,ans,voyage);
        return ans;
    }
};
