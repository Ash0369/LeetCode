//Method-1 : Brute Force

vector<int>vec;
void ele(TreeNode *root)
{
    if(root==NULL)
        return;
    ele(root->left);
    vec.push_back(root->val);
    ele(root->right);
}
TreeNode *make_tree(int low,int high)
{
    if(low>high)
        return NULL;
    int mid=(low+high)>>1;
    
    TreeNode *temp=new TreeNode(vec[mid]);
    
    temp->left=make_tree(low,mid-1);
    temp->right=make_tree(mid+1,high);
    
    return temp;
}
class Solution 
{
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        vec.clear();
        ele(root);
        return make_tree(0,vec.size()-1);
    }
};
