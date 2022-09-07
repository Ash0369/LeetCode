//Method-1 : Using Stack

void recover(TreeNode *root,set<int>&st)
{
    if(root==NULL)
        return;
    
    if(root->left)
    {
        root->left->val=(2*root->val)+1;
        st.insert((2*root->val)+1);
    }
        
    if(root->right)
    {
        root->right->val=(2*root->val)+2;
        st.insert((2*root->val)+2);
    }
        
    
    recover(root->left,st);
    recover(root->right,st);
}

class FindElements 
{
public:
    set<int>st;
    FindElements(TreeNode* root) 
    {
        root->val=0;
        st.insert(0);
        recover(root,st);
    }
    
    bool find(int target) 
    {
        if(st.find(target)==st.end())
            return false;
        
        return true;
    }
};
