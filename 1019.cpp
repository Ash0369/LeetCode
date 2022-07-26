//Method-1 : Brute Force

class Solution 
{
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>result;
        while(head!=NULL)
        {
            ListNode*ptr=head;
            while(ptr!=NULL)
            {
                if(ptr->val>head->val)
                {
                    result.push_back(ptr->val);
                    break;
                }
                ptr=ptr->next;
            }
            if(ptr==NULL)
            {
                result.push_back(0);
            }
            head=head->next;
        }
        return result;
    }
};

//Method-2 : Using Satck

class Solution 
{
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>result;
        stack<int>curr;
        stack<int>past;
        while(head!=NULL)
        {
            curr.push(head->val);
            head=head->next;
        }
        past.push(curr.top());
        curr.pop();
        result.push_back(0);
        while(!curr.empty())
        {
            while(!past.empty() && curr.top()>=past.top())
            {
                past.pop();
            }
            if(past.empty())
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(past.top());
            }
            past.push(curr.top());
            curr.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
