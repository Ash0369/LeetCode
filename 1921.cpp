class Solution 
{
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n=speed.size();
        vector<double>t;
        for(int i=0;i<speed.size();i++)
        {
            t.push_back(1.00*dist[i]/speed[i]);
        }
        sort(t.begin(),t.end());
        int cnt=0;
        int av=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]<=av)
            {
                break;
            }
            cnt++;
            av++;
        }
        return cnt;
    }
};
