class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int boat=0;
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        
        while(i<j)
        {
            int w=people[j]+people[i];
            if(w<=limit)
            {
                boat++;
                i++;
                j--;
            }
            else
            {
                j--;
                boat++;
            }
        }
        if(i==j)
        {
            boat++;
        }
        return boat;
    }
};
