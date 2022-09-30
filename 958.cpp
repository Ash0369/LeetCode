//Method-1 : 

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


//Method-2 : 

int nodes(TreeNode *root)
{
    if(root==NULL)
        return 0;
    return 1+nodes(root->left)+nodes(root->right);
}

bool check(TreeNode *root,int count,int index)
{
    if(root==NULL)
        return true;
    if(index>=count)
        return false;
    
    return check(root->left,count,2*index+1)&check(root->right,count,2*index+2);
}
class Solution 
{
public:
    bool isCompleteTree(TreeNode* root) 
    {
        int count=nodes(root);
        return check(root,count,0);
    }
};
