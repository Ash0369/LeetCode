bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength,int mid)
{
    int n=tasks.size();
    int m=workers.size();
    if(m<mid)
    {
        return false;
    }
    multiset<int>st(workers.begin(),workers.end());
    for(int i=n-mid;i<n;i++)
    {
        if(tasks[i]<=(*st.rbegin()))
        {
            st.erase(st.find(*st.rbegin()));
        }
        else if(pills<=0)
        {
            return false;
        }
        else
        {
            pills--;
            int req=tasks[i]-strength;
            auto index=st.lower_bound(req);
            if(index==st.end())
            {
                return false;
            }
            st.erase(index);
        }
    }
    return true;
}
class Solution 
{
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        sort(tasks.begin(),tasks.end(),greater<int>());
        
        int n=tasks.size();
        int m=workers.size();
        
        int left=0;
        int right=n;
        int ans=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            
            //Check mid number of task can be done
            //Take smallest task strength
            //Take maximum in worker
         
            if(check(tasks,workers,pills,strength,mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};
