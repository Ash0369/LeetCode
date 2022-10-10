class CBTInserter 
{
public:
    TreeNode *rt;
    queue<TreeNode*>q;
    CBTInserter(TreeNode* root) 
    {
        rt=root;
        q.push(root);
        bool res=false;
        while(!q.empty() && !res)
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                auto p=q.front();
                if(p->left && p->right)
                    q.pop();
                else
                {
                    if(p->left)
                        q.push(p->left);
                    if(p->right)
                        q.push(p->right);
                    res=true;
                    break;
                }
                q.push(p->left);
                q.push(p->right);
            }
        }
    }
    
    int insert(int val) 
    {
        while(!q.empty() && q.front()->left && q.front()->right)
            q.pop();
        TreeNode *temp=new TreeNode(val);
        if(!q.front()->left)
            q.front()->left=temp;
        
        else
            q.front()->right=temp;
        
        q.push(temp);
        return q.front()->val;
    }
    
    TreeNode* get_root() 
    {
        return rt;
    }
};
