class Solution 
{
public:
    int maximumScore(int a, int b, int c) 
    {
        vector<int>vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        
        sort(vec.begin(),vec.end());
        
        int ele=vec[2];
        int score=0;
        while(ele<(vec[0]+vec[1]))
        {
            score++;
            vec[1]--;
            vec[0]--;
        }
        score=score+vec[0]+vec[1];
        return score;
        
    }
};
