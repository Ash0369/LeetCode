long long int ans=0;
const int mod=1e9+7;
int total_sum(TreeNode *&root)
{
    if(root==NULL)
        return 0;
    return root->val+total_sum(root->left)+total_sum(root->right);
}
int maxp(TreeNode *root,int &tot_sum)
{
    if(root==NULL)
        return 0;
        
    long long int l=maxp(root->left,tot_sum);
    long long int r=maxp(root->right,tot_sum);
    
    long long int a=(tot_sum-r)*r;
    long long int b=(tot_sum-l)*l;
    ans=max(ans,max(a,b));
    
    return root->val+l+r;
    
}
class Solution 
{
public:
    int maxProduct(TreeNode* root) 
    {
        ans=0;
        int tot_sum=total_sum(root);
        maxp(root,tot_sum);
        return ans%mod;
    }
};
