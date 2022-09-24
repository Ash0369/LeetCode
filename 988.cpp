string smallest(TreeNode *root,string s)
{
   if(root==NULL)
       return "";
    string ch="";
    ch.push_back(int(root->val+97));
    s=ch+s;
    string x=smallest(root->left,s);
    string y=smallest(root->right,s);
    if(x=="" && y=="")
        return s;
    if(x=="" && y!="")
        return y;
    if(x!="" && y=="")
        return x;
    
    if(x<y)
        return x;
    
    return y;
}
class Solution 
{
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        string s="";
        return smallest(root,s);
    }
};
