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
