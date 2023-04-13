class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i=0;
        int j=0;
        int n=pushed.size();
        stack<int>st;
        while(i<n && j<n)
        {
            st.push(pushed[i]);
            while(j<n && !st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            i++;
        }
        while(j<n)
        {
            if(popped[j]!=st.top())
            {
                return false;
            }
            st.pop();
            j++;
        }
        return true;
    }
};
