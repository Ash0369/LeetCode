class Solution 
{
public:
    int maximum69Number (int num) 
    {
        bool op=true;
        stack<int>st;
        while(num>0)
        {
            int a=num%10;
            st.push(a);
            num=num/10;
        }
        
        int ans=0;
        while(!st.empty())
        {
            int a=st.top();
            st.pop();
            if(a==6 && op)
            {
                a=9;
                op=false;
            }
            ans=ans*10 + a;
        }
        return ans;
    }
};
