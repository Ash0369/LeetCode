//Method-1 : Brute Force ,Time Complexity O(nlog(n)) and Space Complexity O(n)+O(n)

class Solution 
{
public:
    int pairSum(ListNode* head) 
    {
        vector<int>vec;
        while(head!=NULL)
        {
            vec.push_back(head->val);
            head=head->next;
        }
        int n=vec.size();
        vector<int>sum;
        for(int i=0;i<=(n/2)-1;i++)
        {
            int temp;
            temp=vec[i]+vec[n-1-i];
            sum.push_back(temp);
        }
        sort(sum.begin(),sum.end(),greater<int>());
        return sum[0];
    }
};

//Method-2 : 2 Pointers approach O(n) Time and Space Complexity

class Solution 
{
public:
    int pairSum(ListNode* head) 
    {
        stack<int>half;
        ListNode* fast=head;
        ListNode* slow=head;

        //Finding middle element 
        while(fast!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        //Now put element to stack till we reach the centreof linked list

        ListNode* putter=head;
        while(putter!=slow)
        {
            half.push(putter->val);
            putter=putter->next;
        }

        //Now we will take out elements from stack as well as continue the puttter and compare both the element.

        int max_sum=INT_MIN;

        while(!half.empty())
        {
            max_sum=max(max_sum,half.top()+putter->val);
            putter=putter->next;
            half.pop();
        }

        return max_sum;
    }
};
