bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]<v2[0])
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        sort(coordinates.begin(),coordinates.end(),cmp);
        for(int i=1;i<coordinates.size()-1;i++)
        {
            int s1=(coordinates[i][1]-coordinates[i-1][1])*(coordinates[i][0]-coordinates[i+1][0]);
            
            int s2=(coordinates[i][1]-coordinates[i+1][1])*(coordinates[i][0]-coordinates[i-1][0]);
            if(s1!=s2)
            {
                return false;
            }
        }
        return true;
        
    }
    
};
