class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return root;
        queue<Node*>st;
        st.push(root);
        while(!st.empty())
        {
            int n=st.size();
            for(int i=0;i<n;i++)
            {
                Node *temp=st.front();
                st.pop();
                if(i<n-1)
                {
                    temp->next=st.front();
                }
                else
                {
                    temp->next=NULL;
                }
                
                if(temp->left)
                    st.push(temp->left);
                
                if(temp->right)
                    st.push(temp->right);
            }
        }
        
        return root;
    }
};
