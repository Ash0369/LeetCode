bool comparator(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[0]!=vec2[0])
        return vec1[0]>vec2[0];
    else
        return vec1[1]<vec2[1];
}
class Solution 
{
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        int n=properties.size();
        sort(properties.begin(),properties.end(),comparator);
        int count=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(properties[i][1]<mx)
                count++;
            
            mx=max(mx,properties[i][1]);
        }
        return count;
    }
};
