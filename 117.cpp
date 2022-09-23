//Method-1 : 


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


//Method-2 : 


class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return root;
        Node *head=root;
        while(head!=NULL)
        {
            Node *temp=head;
            Node *ptr=new Node(-1);
            Node *dummy=ptr;
            while(head!=NULL)
            {
                if(head->left)
                {
                    ptr->next=head->left;
                    ptr=head->left;
                }
                if(head->right)
                {
                    ptr->next=head->right;
                    ptr=head->right;
                }
                head=head->next;
            }
            head=dummy->next;
        }
        
        return root;
    }
};
