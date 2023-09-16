class Solution 
{
public:
    int minimumRightShifts(vector<int>&vec) 
    {
        
        int n=vec.size();
        if(n==1){
            return 0;
        }
        
        if(is_sorted(vec.begin(),vec.end()))
        {
            return 0;
        }
        int ans=200;
        for(int i=0;i<n;i++)
        {
            vec.push_back(vec[i]);
            if(is_sorted(vec.begin()+i+1,vec.end()))
            {
                ans=min(ans,n-i-1);
            }
        }
        if(ans==200)
        {
            return -1;
        }
        return ans;
        int change=0;
        int last=0;
        for(int i=1;i<n;i++)
        {
            if(vec[i]>=vec[i-1])
            {
                last=i;
            }
            else{
                break;
            }
        }
        int last2=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(vec[i]<=vec[i+1])
            {
                last2=i;
            }
            else
            {
                break;
            }
        }
        if(last2>last+1)
        {
            return -1;
        }
        if(last==0 && last2==n-1)
        {
            if(n==2)
            {
                if(vec[0]>vec[1])
                    return 1;
                return 0;
            }
            return -1;
        }
        return n-last-1;
    }
};
