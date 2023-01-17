class Solution 
{
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.size();
        int last_z=-1;
        vector<int>one(n+1,0);
        vector<int>zero(n+1,0);
        for(int i=n;i>=0;i--)
        {
            if(i==n)
            {
                one[i]=0;
                zero[i]=0;
            }
            else if(s[i]=='1')
            {
                one[i]=one[i+1]+1;
                zero[i]=zero[i+1];
            }
            else
            {
                one[i]=one[i+1];
                zero[i]=zero[i+1]+1;
            }
        }
        int to=one[0];
        int ans=n;
        for(int i=0;i<=n;i++)
        {
            int op=to-one[i]+zero[i];
            ans=min(ans,op);
        }
        return ans;
    }
};
