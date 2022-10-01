//Method-1 : 

class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        stack<int>st;
        vector<int>left;
        vector<int>right;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                left.push_back(0);
            else
                left.push_back(st.top()+1);
            
            st.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && heights[st2.top()]>=heights[i])
                st2.pop();
            if(st2.empty())
                right.push_back(n-1);
            else
                right.push_back(st2.top()-1);
            
            st2.push(i);
        }
        int max_area=0;
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++)
        {
            int area=(right[i]-left[i]+1)*heights[i];
            max_area=max(max_area,area);
        }
        return max_area;
    }
};


//Method-2 : 


class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        int max_area=0;
        stack<int>st;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int r=i;
                int h=heights[st.top()];
                st.pop();
                int l=-1;
                if(!st.empty())
                    l=st.top();
                int area=(r-l-1)*h;
                max_area=max(max_area,area);
            }
            st.push(i);
        }
        return max_area;
    }
};
