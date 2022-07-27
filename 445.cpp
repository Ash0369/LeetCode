//Method-1 : Using Stack

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<ListNode*>st1;
        stack<ListNode*>st2;
        ListNode* temp=l1;
        while(temp!=NULL)
        {
            st1.push(temp);
            temp=temp->next;
        }
        temp=l2;
        while(temp!=NULL)
        {
            st2.push(temp);
            temp=temp->next;
        }
        stack<int>result;
        int d=0;
        while(!st1.empty() && !st2.empty())
        {
            int a=st1.top()->val+st2.top()->val+d;
            if(a>9)
            {
                a=a-10;
                d=1;
            }
            else
            {
                d=0;
            }
            result.push(a);
            st1.pop();
            st2.pop();
        }
        while(!st1.empty())
        {
            int a=st1.top()->val+d;
            if(a>9)
            {
                a=a-10;
                d=1;
            }
            else
            {
                d=0;
            }
            result.push(a);
            st1.pop();
        }

        while(!st2.empty())
        {
            int a=st2.top()->val+d;
            if(a>9)
            {
                a=a-10;
                d=1;
            }
            else
            {
                d=0;
            }
            result.push(a);
            st2.pop();
        }

        if(d==1)
        {
            result.push(d);
        }

        ListNode* head=new ListNode(result.top());
        result.pop();
        ListNode* pointer=head;

        while(!result.empty())
        {
            pointer->next=new ListNode(result.top());
            pointer=pointer->next;
            result.pop();
        }

        return head;
        
    }
};
