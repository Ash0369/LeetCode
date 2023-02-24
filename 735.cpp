class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n=asteroids.size();
        stack<int>st;
        st.push(asteroids[0]);
        for(int i=1;i<n;i++)
        {
            int ele=asteroids[i];
            bool res=true;
            while(!st.empty() && (ele<0 && st.top()>0))
            {
                if(abs(st.top())>abs(ele))
                {
                    res=false;
                    break;
                }
                else if(abs(st.top())==abs(ele))
                {
                    st.pop();
                    res=false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(res)
            {
                st.push(ele);
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
