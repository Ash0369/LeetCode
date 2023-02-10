//Method-1 : Monotonic Stack

class Solution 
{
public:
    int minNumberOperations(vector<int>& target) 
    {
        int n=target.size();
        stack<int>st;
        int op=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(target[i]);
                op+=target[i];
            }
            else if(st.top()>=target[i])
            {
                st.push(target[i]);
            }
            else
            {
                op+=target[i]-st.top();
                st.push(target[i]);
            }
        }
        return op;
    }
};


//Method-2: Dynamic Programming


class Solution 
{
public:
    int minNumberOperations(vector<int>& target) 
    {
        int n=target.size();
        int op=target[0];
        for(int i=1;i<n;i++)
        {
            if(target[i]>target[i-1])
            {
                op+=target[i]-target[i-1];
            }
        }
        return op;
    }
};
