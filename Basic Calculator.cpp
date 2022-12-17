bool check(char c)
{
    if(c=='-' || c=='+' || c=='(' || c==')' || c==' ')
        return false;
    return true;
}
class Solution 
{
public:
    int calculate(string s) 
    {
        stack<int>st;
        int n=s.length();
        int sum=0;
        int sign=1;
        for(int i=0;i<n;i++)
        {
            if(check(s[i]))
            {
                int num=0;
                while(i<n && check(s[i]))
                {
                    num=(num*10)+(s[i]-'0');
                    i++;
                }
                sum+=(num*sign);
                i--;
            }
            else if(s[i]=='+')
            {
                sign=1;
            }
            else if(s[i]=='-')
            {
                sign=-1;
            }
            else if(s[i]=='(')
            {
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                sum=st.top()*sum;//As top has sign
                st.pop();
                sum+=st.top();//with value before +( or -(
                st.pop();
            }
        }
        return sum;
    }
};
