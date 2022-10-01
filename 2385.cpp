TreeNode *find(TreeNode *root,int value)
{
    if(root==NULL)
        return root;
    if(root->val==value)
        return root;
    TreeNode *l=find(root->left,value);
    if(l!=NULL)
        return l;
    return find(root->right,value);
        
}
class Solution 
{
public:
    int amountOfTime(TreeNode* root, int start) 
    {
        map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            int k=st.size();
            for(int i=0;i<k;i++)
            {
                TreeNode* temp=st.front();
                if(temp->left)
                {
                     mp[temp->left]=temp;
                     st.push(temp->left);
                }
                   
                if(temp->right)
                {
                    mp[temp->right]=temp;
                    st.push(temp->right);
                }
                st.pop();
            }
        }
        
        TreeNode *node=find(root,start);
        
        int time=0;
        map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->val!=root->val && vis.find(mp[temp])==vis.end())
                {
                    vis[mp[temp]]=1;
                    q.push(mp[temp]);
                }
                if(temp->left && vis.find(temp->left)==vis.end())
                {
                    vis[temp->left]=1;
                    q.push(temp->left);
                }
                if(temp->right && vis.find(temp->right)==vis.end())
                {
                    vis[temp->right]=1;
                    q.push(temp->right);
                }
            }
            time++;
        }
        return time-1;   
    }
};
