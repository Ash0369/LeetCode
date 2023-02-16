class Solution 
{
public:
    int minimumScore(string s, string t) 
    {
        int n=t.size();
        int m=s.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        
        int i=0;
        int j=0;
        for(i=0;i<n;i++)
        {
            while(j<m && s[j]!=t[i])
            {
                j++;
            }
            if(j==m)
            {
                prefix[i]=-1;
            }
            else
            {
                prefix[i]=j;
                j++;
            }
        }
        j=m-1;
        for(i=n-1;i>=0;i--)
        {
            while(j>=0 && s[j]!=t[i])
            {
                j--;
            }
            if(j==-1)
            {
                suffix[i]=-1;
            }
            else
            {
                suffix[i]=j;
                j--;
            }
        }
        
        int ans=INT_MAX;
        if(prefix[n-1]!=-1)
        {
            return 0;
        }
        //Deleting suffix
        for(int i=n-1;i>=0;i--)
        {
            if(suffix[i]==-1)
            {
                ans=min(ans,(i-0+1));
                break;
            }
        }
        //Deleting Prefix
        for(int i=0;i<n;i++)
        {
            if(prefix[i]==-1)
            {
                ans=min(ans,(n-1-i+1));
                break;
            }
        }
        
        //Delete in Middle
        
        j=0;
        while(j<n && suffix[j]==-1)
        {
            j++;
        }
        
        for(int i=0;i<n;i++)
        {
            j=max(j,i+1);
            if(prefix[i]!=-1)
            {
                while(j<n && suffix[j]<=prefix[i])
                {
                    j++;
                }
                if(j<n)
                {
                    ans=min(ans,(j-1)-(i+1)+1);
                }
            }
        }
        
        return ans;   
    }
};
