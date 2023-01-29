class Solution 
{
public:
    #define ll long long
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n=weights.size();
        vector<int>score;
        //score.push_back(weights[0]+weights[n-1]); will be added in both soin difference 0
        for(int i=0;i<n-1;i++)
        {
            score.push_back(weights[i]+weights[i+1]);
        }
        sort(score.begin(),score.end());
        
        ll int mx=0;
        ll int min=0;
        
        for(int i=0;i<k-1;i++)
        {
            mx=mx+score[score.size()-1-i];
            min=min+score[i];
        }
        return mx-min;
    }
};
