#define pii pair<double,int>
class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        int n=points.size();
        vector<vector<int>>ans;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<n;i++)
        {
            double a=pow(points[i][0],2);
            double b=pow(points[i][1],2);
            double c=pow(a+b,0.5);
            pq.push({c,i});
        }
        while(k>0)
        {
            auto x=pq.top().second;
            pq.pop();
            ans.push_back({points[x][0],points[x][1]});
            k--;
        }
        return ans;                  
    }
};
