class Solution 
{
public:
    int countPairs(vector<vector<int>>& coordinates, int k) 
    {
        int ans=0;
        int n=coordinates.size();
        sort(coordinates.begin(),coordinates.end());
        map<int,int>mp;
        vector<vector<int>>c;
        int index=0;
        for(int i=0;i<n;i++)
        {
            mp[index]++;
            c.push_back(coordinates[i]);
            i++;
            while(i<n && coordinates[i]==c.back())
            {
                i++;
                mp[index]++;
            }
            i--;
            index++;
        }
        n=c.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<min(n,i+100);j++)
            {
                int xr=c[i][0]^c[j][0];
                xr+=c[i][1]^c[j][1];
                if(xr==k)
                {
                    ans+=mp[i]*mp[j];
                }
            }
        }
        if(k==0)
        {
            for(auto x:mp)
            {
                ans+=(1LL*x.second*(x.second-1))/2;
            }
        }
        return ans;
    }
};
