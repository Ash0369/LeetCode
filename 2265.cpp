int cnt=0;
pair<int,int> avg(TreeNode *root)
{
    if(root==NULL)
    {
        return make_pair(0,0);
    }
    auto l=avg(root->left);
    auto r=avg(root->right);
    
    if(l.second==0 && r.second==0)
    {
        cnt++;
        return make_pair(root->val,1);
    }
    
    int sum=l.first+r.first+root->val;
    if(sum/(l.second+r.second+1)==root->val)
    {
        cnt++;
    }
    
    return make_pair(sum,l.second+r.second+1);
}
class Solution 
{
public:
    int averageOfSubtree(TreeNode* root) 
    {
        cnt=0;
        avg(root);
        return cnt;
    }
};
