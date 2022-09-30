class Solution 
{
public:
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                TreeNode *temp=q.front();
                if(temp==NULL)
                {
                    while(!q.empty())
                    {
                        if(q.front()!=NULL)
                            return false;
                        q.pop();
                    }
                    return true;
                }
                
                q.push(temp->left);
                q.push(temp->right);
                q.pop();
            }
        }
        return true;
    }
};
