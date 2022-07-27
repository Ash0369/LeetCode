//Method-1 : Using Some extra vector

class Solution 
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>pos;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* aftr=NULL;
        int count=0;
        while(curr!=NULL)
        {
            aftr=curr->next;
            if(prev!=NULL && aftr!=NULL)
            {
                if((curr->val>prev->val && curr->val>aftr->val) || (curr->val<prev-> val  && curr->val<aftr->val))
                {
                    pos.push_back(count);
                }
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        vector<int>result;
        if(pos.size()<2)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int min_val=INT_MAX;
        for(int i=0;i<pos.size()-1;i++)
        {
            if(abs(pos[i]-pos[i+1])<min_val)
            {
                min_val=abs(pos[i]-pos[i+1]);
            }
        }
        result.push_back(min_val);
        result.push_back(pos[pos.size()-1]-pos[0]);
        return result;
    }
};


//Method-2 : Reducing space used

class Solution 
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* aftr=NULL;
        int min_value=INT_MAX;
        int max_value=INT_MIN;
        int last_index=-1;
        int first_index=-1;
        int count=0;
        while(curr!=NULL)
        {
            aftr=curr->next;
            if(prev!=NULL && aftr!=NULL)
            {
                if((curr->val>prev->val && curr->val>aftr->val) || (curr->val<prev-> val  && curr->val<aftr->val))
                {
                    if(last_index==-1)
                    {
                        last_index=count;
                        first_index=count;
                    }
                    else
                    {
                        max_value=max(max_value,abs(first_index-count));

                        min_value=min(min_value,abs(last_index-count));

                        last_index=count;
                    }

                }
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        vector<int>result;
        if(last_index==-1 || max_value==INT_MIN)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(min_value);
        result.push_back(max_value);
        return result;
    }
};
