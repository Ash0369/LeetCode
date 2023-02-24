class Solution 
{
public:
    bool asteroidsDestroyed(long long int mass, vector<int>& asteroids) 
    {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        for(auto x:asteroids)
        {
            if(x>mass)
            {
                return false;
            }
            mass+=x;
        }
        return true;
    }
};
