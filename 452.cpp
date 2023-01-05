bool cmp(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[0]<=vec2[0])
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end(),cmp);
        int shot=0;
        int minend=INT_MIN;
        for(auto x:points)
        {
            if(shot==0 || x[0]>minend)
            {
                shot++;
                minend=x[1];
            }
            else
            {
                minend=min(minend,x[1]);
            }
        }
        return shot;
    }
};
