#define ll long long
bool perform(map<int,ll int>&mp,int x)
{
    bool res=true;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int cnt=0;
            while(x%i==0)
            {
                x=x/i;
                cnt++;
            }
            if(mp[i]>0)
            {
                res=false;
            }
            mp[i]+=cnt;
        }
    }
    if(x>1)
    {
        if(mp[x]>0)
        {
            res=false;
        }
        mp[x]+=1;
    }
    return res;
}
void removee(map<int,ll int>&mp,int x)
{
    //cout<<x<<endl;
    bool res=true;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int cnt=0;
            while(x%i==0)
            {
                x=x/i;
                cnt++;
            }
            mp[i]-=cnt;
        }
    }
    if(x>1)
    {
        mp[x]-=1;
    }
}
class Solution 
{
public:
    int findValidSplit(vector<int>& nums) 
    {
        ll int mul=1;
        map<int,ll int>mp;
        int n=nums.size();
        int last=n+1;
        vector<int>possible;
        perform(mp,nums[0]);
        for(int j=1;j<n;j++)
        {
            int x=nums[j];
            bool res=perform(mp,x);
            if(res==true)
            {
                possible.push_back(j);
                removee(mp,x);
            }
            else
            {
                while(possible.size()>0)
                {
                    perform(mp,nums[possible.back()]);
                    possible.pop_back();
                }
            }
        }
        if(possible.size()==0)
        {
            return -1;
        }
        return possible[0]-1;
    }
};
