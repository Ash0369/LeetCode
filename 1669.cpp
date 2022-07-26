class Solution 
{
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* fast=list1;
        ListNode* slow=list1;
        int n=b-a;
        while(n>0)
        {
            fast=fast->next;
            n--;
        }
        while(a>1)
        {
            slow=slow->next;
            fast=fast->next;
            a--;
        }
        fast=fast->next;
        slow->next=list2;
        while(list2->next!=NULL)
        {
            list2=list2->next;
        }
        list2->next=fast->next;
        return list1;
    }
};
