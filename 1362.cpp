//Method-1 : 

class Solution 
{
public:
    int distinctPrimeFactors(vector<int>& nums) 
    {
        unordered_set<int>st;
        for(auto x:nums)
        {
            int d=2;
            while(x>1 && d<=sqrt(1000))
            {
                if(x%d==0)
                {
                    st.insert(d);
                    x=x/d;
                }
                else
                {
                    d++;
                }
            }
            if(x!=1)
            {
                st.insert(x);
            }
        }
        return st.size();
    }
};

//Method-2 : 

class Solution 
{
public:
    vector<int> closestDivisors(int num) 
    {
        for(int i=sqrt(num+2);i>=1;i--)
        {
            if((num+1)%i==0)
            {
                return {i,(num+1)/i};
            }
            if((num+2)%i==0)
            {
                return {i,(num+2)/i};
            }
            
        }
       
        return {};
    }
};
