//Method-1 :

#define ll long long
class Solution 
{
public:
    long long findScore(vector<int>&vec) 
    {
        ll int ans=0;
        int n=vec.size();
        multiset<int>st(vec.begin(),vec.end());
        map<int,set<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[vec[i]].insert(i);
        }
        int k=1;
        while(!st.empty())
        {
            int val=(*st.begin());
            
            int i=(*mp[val].begin());
            
            ans+=val;
            st.erase(st.begin());
            mp[vec[i]].erase(i);
            if(i-1>=0)
            {
                if(mp[vec[i-1]].find(i-1)!=mp[vec[i-1]].end())
                {
                    mp[vec[i-1]].erase(i-1);
                    st.erase(st.find(vec[i-1]));
                }
            }
            if(i+1<n)
            {
                if(mp[vec[i+1]].find(i+1)!=mp[vec[i+1]].end())
                {
                    mp[vec[i+1]].erase(i+1);
                    st.erase(st.find(vec[i+1]));
                }
            }
        }
        return ans;
    }
};

//Method-2 : 


#define ll long long
class Solution 
{
public:
    long long findScore(vector<int>&nums) 
    {
        ll int ans=0;
        int n=nums.size();
        set<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            st.insert({nums[i],i});
        }
        for(auto &x:st)
        {
            if(nums[x.second]==-1)
            {
                continue;
            }
            ans+=x.first;
            nums[x.second]=0;
            if(x.second-1>=0)
            {
                nums[x.second-1]=-1;
            }
            if(x.second+1<n)
            {
                nums[x.second+1]=-1;
            }
        }
        return ans;
    }
};
