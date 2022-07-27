//Method-1 : Using Recursion

Node* flattend(Node* head,Node* aftr)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->child!=NULL)
        {
            Node* ptr=flattend(temp->child,temp->next);
            temp->child=NULL;
            temp->next=ptr;
            ptr->prev=temp;
        }
        else if(temp->next==NULL && temp->child==NULL)
        {
            break;
        }
        temp=temp->next;
    }
    if(aftr!=NULL)
    {
        aftr->prev=temp;
        temp->next=aftr;
    }

    return head;
}
class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        if(head==NULL)
        {
            return head;
        }
        return flattend(head,NULL);
    }
};


//Method-2 : Using Stack

class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        Node* ptr=head;
        stack<Node*>st;
       while(ptr!=NULL)
        {
            if(ptr->child)
            {
                if(ptr->next)
                {
                    st.push(ptr->next);
                }
                ptr->child->prev=ptr;
                ptr->next=ptr->child;
                ptr->child=NULL;
            }
            if(ptr->next==NULL && !st.empty())
            {
                ptr->next=st.top();
                st.top()->prev=ptr;
                st.pop();
            }
            ptr=ptr->next;
        }
        return head;
    }
};
