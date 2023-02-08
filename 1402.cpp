int cook(vector<int>&sat,int ind)
{
    int till=1;
    int ans=0;
    for(int i=ind;i<sat.size();i++)
    {
        ans+=till*sat[i];
        till++;
    }
    return ans; 
}
class Solution 
{
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int ans=0;
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<n;i++)
        {
            ans=max(ans,cook(satisfaction,i));
        }
        return ans;
    }
};
