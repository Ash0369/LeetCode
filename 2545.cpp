int m;
bool cmp(vector<int>&v1,vector<int>&v2)
{
    return v1[m]>v2[m];
}
class Solution 
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        m=k;
        sort(score.begin(),score.end(),cmp);
        return score;
    }
};
