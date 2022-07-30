//Method-1 : Using Map

Node* copy(Node* head,map<Node*,Node*>&mp)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(mp.find(head)==mp.end())
    {
        Node* temp=new Node(head->val);
        mp[head]=temp;
        mp[head]->next=copy(head->next,mp);
        mp[head]->random=copy(head->random,mp);
    }
    return mp[head];
}
class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        map<Node*,Node*>mp;
        return copy(head,mp);
    }
};

//Method-2 : Optimized Approach

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        Node* temp=head;

        //First making LL

        while(temp!=NULL)
        {
            Node* new_node=new Node(temp->val);
            Node* curr=temp;
            temp=temp->next;
            curr->next=new_node;
            new_node->next=temp;
        }

        //Now connect random

        temp=head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        //Removing older item

        temp=head;
        Node* dummy=new Node(0);
        Node* copy,*copy_tail=dummy;

        while(temp!=NULL)
        {
            Node* nxt=temp->next->next;
            copy=temp->next;
            copy_tail->next=copy;
            copy_tail=copy;

            temp->next=nxt;
            temp=nxt;
        }
         return dummy->next;
    }
};
