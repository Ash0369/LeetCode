int find(TreeNode* root,int&sum)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=find(root->left,sum);
    int r=find(root->right,sum);
    sum=sum+abs(r-l);
    return root->val+r+l;
    
    
}
class Solution 
{
public:
    int findTilt(TreeNode* root) 
    {
        int sum=0;
        find(root,sum);
        return sum;
    }
};
