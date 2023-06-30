class Solution 
{
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        int n=positions.size();
        vector<vector<int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({positions[i],i});
        }
        sort(vec.begin(),vec.end());
        stack<pair<int,int>>st;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(directions[vec[i][1]]=='L')
            {
                if(st.empty())
                {
                    //just push
                    ans.push_back({vec[i][1],healths[vec[i][1]]});
                }
                else
                {
                    //check for collision
                    int energy=healths[vec[i][1]];
                    bool survive=true;
                    while(!st.empty())
                    {
                        if(st.top().first>energy)
                        {
                            st.top().first--;
                            survive=false;
                            break;
                        }
                        else if(st.top().first==energy)
                        {
                            st.pop();

                            survive=false;
                            break;
                        }
                        else
                        {
                            st.pop();
                            energy--;
                        }
                    }
                    if(survive==true)
                    {
                        ans.push_back({vec[i][1],energy});
                    }
                }
            }
            else
            {
                st.push({healths[vec[i][1]],vec[i][1]});//energyand coordinate
            }
        }
        while(!st.empty())
        {
            ans.push_back({st.top().second,st.top().first});
            st.pop();
        }
        vector<int>res;
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        {
            res.push_back(x[1]);
        }
        return res;
    }
};
