//Method-1 : 

TreeNode* lca(TreeNode *root,int &start,int &end)
{
    if(root==NULL)
        return NULL;
    if(root->val==start || root->val==end)
        return root;
    TreeNode* l=lca(root->left,start,end);
    TreeNode* r=lca(root->right,start,end);
    
    if(l!=NULL && r!=NULL)
        return root;
   
    if(l!=NULL)
        return l;
    return r;
}

bool reach(TreeNode *root,int value,string &s)
{
    if(root==NULL)
        return false;
    if(root->val==value)
        return true;
    bool a=reach(root->left,value,s);
    bool b=reach(root->right,value,s);
    
    if(a)
        s.push_back('L');
    if(b)
        s.push_back('R');
    
    return a|b;
}
class Solution 
{
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode *ancestor=lca(root,startValue,destValue);
        string start,end;
        reach(ancestor,startValue,start);
        reach(ancestor,destValue,end);
        
        string res="";
        for(auto x:start)
            res.push_back('U');
         reverse(end.begin(),end.end());
         for(auto x:end)
            res.push_back(x);
        
        return res;

    }
};


//Method-2 : 

bool reach(TreeNode *root,int &value,string &s)
{
    if(root==NULL)
        return false;
    if(root->val==value)
        return true;
    bool a=reach(root->left,value,s);
    bool b=reach(root->right,value,s);
    
    if(a)
        s.push_back('L');
    if(b)
        s.push_back('R');
    
    return a|b;
}
class Solution 
{
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        //TreeNode *ancestor=lca(root,startValue,destValue);
        string start,end;
        reach(root,startValue,start);
        reach(root,destValue,end);
        
        while(!start.empty() && !end.empty() && start.back()==end.back())
        {
            start.pop_back();
            end.pop_back();
        }
        reverse(end.begin(),end.end());
        return string(start.size(),'U')+end;
    }
};
