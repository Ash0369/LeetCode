#define pii pair<int,int>
#define ll long long
bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]>v2[0])
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        ll int tot=0;
        int mn=1e9;
        vector<vector<int>>vec;
        for(int i=0;i<nums1.size();i++)
        {
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        int index=0;
        while(k--)
        {
            tot+=vec[index][0];
            pq.push({vec[index][1],index});
            index++;
        }
        ll int ans=tot*pq.top().first;
        while(index<nums1.size())
        {
            int i=pq.top().second;
            tot=tot-vec[i][0];
            tot=tot+vec[index][0];
            pq.pop();
            pq.push({vec[index][1],index});
            ll int temp=tot*pq.top().first;
            ans=max(ans,temp);
            index++;
        }
        return ans;
    }
};
