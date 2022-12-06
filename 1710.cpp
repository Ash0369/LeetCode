bool cmp(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[1]>vec2[1])
        return true;
    return false;
}
class Solution 
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        int curr_size=0;
        for(auto x:boxTypes)
        {
            if(x[0]+curr_size<=truckSize)
            {
                curr_size+=x[0];
                ans+=x[0]*x[1];
            }
            else
            {
                int rem=truckSize-curr_size;
                ans+=rem*x[1];
                break;
            }
        }
        return ans;
    } 
};
