class Solution 
{
public:
    int bestClosingTime(string customers) 
    {
        int n=customers.size();
        vector<int>vec(n+2,0);
        for(int i=n-1;i>=0;i--)
        {
            if(customers[i]=='Y')
            {
                vec[i]=1+vec[i+1];
            }
            else
            {
                vec[i]=vec[i+1];
            }
        }
        int ans=1e9;
        int hr=n;
        int cnt=0;
        for(int i=0;i<=n;i++)
        {
            //If close at ith
            int penalty=vec[i]+cnt;
            if(penalty<ans)
            {
                ans=penalty;
                hr=i;
            }
            if(i<n && customers[i]=='N')
            {
                cnt++;
            }
        }
        return hr;
    }
};
