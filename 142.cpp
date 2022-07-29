class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        map<ListNode*,int>mp;
        while(head!=NULL)
        {
            mp[head]++;
            if(mp[head]==2)
            {
                return head;
            }
            head=head->next;
        }
        return NULL;
    }
};
