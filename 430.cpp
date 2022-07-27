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
