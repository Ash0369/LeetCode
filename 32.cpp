class Solution 
{
public:
    int longestValidParentheses(string s)
    {
        stack<int>st;
        st.push(-1);
        int count=0;
        int valid=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
           char x=s[i];
           if(x=='(')
           {
            st.push(i);
           }
           else
           {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }  
                else
                {
                    int temp=i-st.top();
                    if(temp>valid)
                    {
                       valid=temp;
                    }
                }     
            }   
        }
        return valid;
        
    }
};
