class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b)
        {
            if(a==NULL)
            {
                a=headA;
            }
            else
            {
                a=a->next;
            }
            if(b==NULL)
            {
                b=headB;
            }
            else
            {
                b=b->next;
            }
        }
        return a;
        
    }
};
