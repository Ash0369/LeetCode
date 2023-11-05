class Solution 
{
public:
    int getWinner(vector<int>& arr, int k) 
    {
        int n=arr.size();
        set<int>st;
        int x=arr[0];
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>x)
            {
                st.insert(x);
                x=arr[i];
                cnt=1;
                if(cnt==k || cnt==n)
                {
                    return arr[i];
                }
            }
            else
            {
                st.insert(arr[i]);
                cnt++;
                if(cnt==k || cnt==n)
                {
                    return x;
                }
            }
        }
        while(!st.empty())
        {
            if((*st.begin())<x)
            {
                cnt++; 
                if(cnt==k || cnt==n)
                {
                    return x;
                }
            }
            else
            {
                x=*st.begin();
                cnt=0;
            }
            st.erase(*st.begin());
        }
        return -1;
    }
};
