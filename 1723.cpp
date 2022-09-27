class Solution 
{
public:
    bool correct(int &mid,int i,vector<int>&jobs,vector<int>&worker,int &k)
    {
        
        if(i==jobs.size())
            return true;
        for(int j=0;j<k;j++)
        {
            if(worker[j]+jobs[i]<=mid)
            {
                worker[j]+=jobs[i];
                if(correct(mid,i+1,jobs,worker,k))
                    return true;
                worker[j]-=jobs[i];
            }
            if(worker[j] == 0)
                break;
        }
            
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        int low=INT_MIN;
        int high=0;
        int n=jobs.size();
        for(int i=0;i<n;i++)
        {
            low=max(low,jobs[i]);
            high=high+jobs[i];
        }
        int ans=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            vector<int>worker(k,0);
            if(correct(mid,0,jobs,worker,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};
