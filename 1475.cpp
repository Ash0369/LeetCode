//Method-1 : Brute Force

class Solution 
{
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int>res=prices;;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(prices[j]<=prices[i])
                {
                    res[i]=res[i]-prices[j];
                    break;
                }
            }
        }
        return res;
    }
};


//Method-2 : Using Monotonic Stack

class Solution 
{
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int>res=prices;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>prices[i])
                st.pop();
            
            if(!st.empty())
                res[i]=res[i]-st.top();
            
            st.push(prices[i]);
        }
        return res;
    }
};
