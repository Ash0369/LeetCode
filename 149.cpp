class Solution 
{
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        
        int n=points.size();
        int ans=1;
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                if(i==j)
                    continue;
                int x2=points[j][0];
                int y2=points[j][1];
                double slope=(y2-y1)/double(x2-x1);
                if(x2==x1)
                    slope=INT_MIN;
                int cnt=0;
                for(int k=0;k<n;k++)
                {
                    int x3=points[k][0];
                    int y3=points[k][1];
                    
                    if(slope==INT_MIN)
                    {
                        if(x1==x3)
                            cnt++;
                        continue;
                    }
                    double new_lhs=y3-y1;
                    double new_rhs=slope*(x3-x1);
                    if(new_lhs==new_rhs || (abs(new_lhs-new_rhs)<=1e-10))
                    {
                        cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
