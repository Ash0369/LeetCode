//Method-1,2,3 will only work if size of array is samll ,for larger size arrray we have to go with binary search


//Method-1 : Memoization

int longest(vector<int>&nums,int index,int prev,vector<vector<int>>&dp)
{
    if(index==nums.size())
        return 0;
    
    if(dp[index][prev+1]==-1)
    {
        int pick=0;
        if(prev==-1 || nums[index]>nums[prev])
            pick=1+longest(nums,index+1,index,dp);
        
        int not_pick=longest(nums,index+1,prev,dp);
        
        dp[index][prev+1]=max(pick,not_pick);
    }
    return dp[index][prev+1];
}
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return longest(nums,0,-1,dp);
    }
};


//Method-2 : Tabulation


class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int prev=index-1;prev>=-1;prev--)
            {
                int pick=0;
                if(prev==-1 || nums[index]>nums[prev])
                    pick=1+dp[index+1][index+1];
                
                
                int not_pick=dp[index+1][prev+1];
                
                dp[index][prev+1]=max(pick,not_pick);
            }
        }
        return dp[0][0];
    }
};


//Method-3 : Space Optimization

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        vector<int>curr(n+1,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int prev=index-1;prev>=-1;prev--)
            {
                int pick=0;
                if(prev==-1 || nums[index]>nums[prev])
                    pick=1+dp[index+1];
                
                
                int not_pick=dp[prev+1];
                
                curr[prev+1]=max(pick,not_pick);
            }
            dp=curr;
        }
        
        return dp[0];
    }
};


//Method-4 : Optimized Tabuation, by different method
//This method is required when we want to trace back LIS or from dp array we want to generate LIS


class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,1); //dp[i] signify length of longest increasing subsequence which end at i
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;    
    }
};


//Method-5 : 

//We can print Lis from dp array generated in Method-4 , this is not part of Q but will important for other Q


//lis vector contain the final answer.
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,1); 
        vector<int>hash(n+1);
        int ans=INT_MIN;
        
        int last_index=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    if(dp[i]<= 1+dp[prev])
                    {
                        dp[i]=max(dp[i],1+dp[prev]);
                        hash[i]=prev;
                    }
                }
            }
            if(dp[i]>ans)
            {
                ans=max(ans,dp[i]);
                last_index=i;
            }
            
        }
        vector<int>lis;
        lis.push_back(nums[last_index]);
        while(hash[last_index]!=last_index)
        {
            last_index=hash[last_index];
            lis.push_back(nums[last_index]);
        }
        reverse(lis.begin(),lis.end());
        for(auto x:lis)
            cout<<x<<endl;
        return ans;
        
    }
};


//Method-6 : Binary Search

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>bs;
        for(int i=0;i<n;i++)
        {
            int up=lower_bound(bs.begin(),bs.end(),nums[i])-bs.begin();
            if(up==bs.size())
            {
                bs.push_back(nums[i]);
            }
            else
                bs[up]=nums[i];
        }
        return bs.size();
        
    }
};


//Method-7 : 

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=(i-1);j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
       return ans+1;  
    }
};


//Method-8 : 
//https://www.youtube.com/results?search_query=longest+increasing+subsequence


int get_best_candidates(map<int,int>&candidates,int v)
{
    auto it=candidates.lower_bound(v);//smallest value greater then or equal to v
    if(it==candidates.begin())
        return 0;
    it--;//smallest value strictly less then v
    return it->second;
}
void check_and_insert(map<int,int>&candidates,int v,int adv)
{
    if(candidates[v]>=adv)
    {
        return;
    }
    else
    {
        candidates[v]=adv;
        auto it=candidates.find(v);
        it++;
        while(it!=candidates.end() && it->second<=adv)
        {
            auto temp=it;
            it++;
            candidates.erase(temp);
        }
    }
}
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        map<int,int>candidates;
        dp[0]=1;
        candidates[nums[0]]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1+get_best_candidates(candidates,nums[i]);
            check_and_insert(candidates,nums[i],dp[i]);
        }

       return *max_element(dp.begin(),dp.end());  
    }
};
