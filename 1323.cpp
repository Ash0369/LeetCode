//Method-1 : 

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


//Method-2 : 

class Solution 
{
public:
    int maximum69Number (int num) 
    {
        int dup=num;
        bool op=true;
        int last6=-1;
        int cnt=0;
        while(num>0)
        {
            int a=num%10;
            if(a==6)
                last6=cnt;
            num=num/10;
            cnt++;
        }
        num=dup;
        int ans=0;
        if(last6==-1)
            return num;
        ans=num/pow(10,last6+1);
        ans=ans*10 + 9;
        
        ans=ans*(pow(10,last6)) + (num%int(pow(10,last6)));
        return ans;
    }
};
