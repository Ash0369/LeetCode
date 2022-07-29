//Method-1 : Brute Force

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


//Method-2 : Floyd's Algorthim

class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                fast=head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        
        return NULL;
    }
};
