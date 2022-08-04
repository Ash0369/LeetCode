int min_value=INT_MAX;
void distribute(vector<int>&cookies,int index,vector<int>&dist,int max_value)
{
    if(index==cookies.size())
    {
        min_value=min(min_value,max_value);
        return;
    }
    for(int i=0;i<dist.size();i++)
    {
        dist[i]=dist[i]+cookies[index];
        distribute(cookies,index+1,dist,max(max_value,dist[i]));
        dist[i]=dist[i]-cookies[index];
    }
}
class Solution 
{
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {
        min_value=INT_MAX;
        vector<int>dist(k,0);
        distribute(cookies,0,dist,0);
        return min_value;
    }
};
