int dfs(int start,vector<int>&row)
{
    int ele=row[start];
    for(int i=start+1;i<row.size();i++)
    {
        int nele=row[i];
        if(nele==ele+1 && ele%2==0)
        {
            if(i==start+1)
                return 0;
            swap(row[start+1],row[i]);
            return 1;
        }
        if(nele+1==ele && ele%2!=0)
        {
            if(i==start+1)
                return 0;
            swap(row[start+1],row[i]);
            return 1;
        }
        
    }
    return 0;
}
class Solution 
{
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int ans=0;
        for(int i=0;i<row.size();i++)
        {
            int a=dfs(i,row);
            ans+=a;
        }
        return ans;
    }
};
