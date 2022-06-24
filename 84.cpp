class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        stack<int>index;
        vector<int>left_limit(n,0);
        vector<int>right_limit(n,0);

        //Left to Right
        for(int i=0;i<n;i++)
        {
            int a=heights[i];
            int left=0;
            if(index.empty())
            {
                index.push(i);
                left=0;
            }
            else
            {
                while(!index.empty() && heights[index.top()]>=a)
                {
                    index.pop();
                }
                if(index.empty())
                {
                    left=0;
                }
                else
                {
                    left=index.top()+1;
                }
                index.push(i);
            }
            left_limit[i]=left;
        }

        while(!index.empty())
        {
            index.pop();
        }

        
        //Right to left
        for(int i=(n-1);i>=0;i--)
        {
            int a=heights[i];
            int right=n-1;
            if(index.empty())
            {
                index.push(i);
                right=n-1;
            }
            else
            {
                while(!index.empty() && heights[index.top()]>=a)
                {
                    index.pop();
                }
                if(index.empty())
                {
                    right=n-1;
                }
                else
                {
                    right=index.top()-1;
                }
                index.push(i);
            }
            right_limit[i]=right;
        }

        int max_area=0;
        for(int i=0;i<n;i++)
        {
            int temp=(right_limit[i]-left_limit[i]+1)*heights[i];
            if(temp>max_area)
            {
                max_area=temp;
            }
        }
        return max_area;
    }
};
