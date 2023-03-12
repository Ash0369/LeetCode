ListNode *merge(ListNode *node1,ListNode *node2)
{
    ListNode *x=node1;
    ListNode *y=node2;
    ListNode *head=new ListNode(0);
    ListNode *headptr=head;
    
    while(x!=NULL && y!=NULL)
    {
        if(x->val<=y->val)
        {
            headptr->next=x;
            x=x->next;
        }
        else
        {
            headptr->next=y;
            y=y->next;
        }
        headptr=headptr->next;
    }
    while(x!=NULL)
    {
        headptr->next=x;
        x=x->next;
        headptr=headptr->next;
    }
    while(y!=NULL)
    {
        headptr->next=y;
        y=y->next;
        headptr=headptr->next;
    }
    return head->next;
}
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int k=lists.size();
        if(k==0)
        {
            return NULL;
        }
        for(int i=1;i<k;i++)
        {
            ListNode *node1=lists[0];
            ListNode *node2=lists[i];
            
            lists[0]=merge(node1,node2);
        }
        return lists[0];
    }
};
