//Method-1 : 

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        stack<int>st;
        int prev=0;
        int ans=0;
        int n=height.size();
        vector<int>left;
        vector<int>right;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                left.push_back(height[i]);
                st.push(height[i]);
                
            }
            else
            {
                if(st.top()<height[i])
                {
                    st.push(height[i]);
                    left.push_back(height[i]);
                }
                else
                    left.push_back(st.top());
            }
            
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                right.push_back(height[i]);
                st.push(height[i]);
                
            }
            else
            {
                
                if(st.top()<height[i])
                {
                    st.push(height[i]);
                    right.push_back(height[i]);
                }
                else
                    right.push_back(st.top());
            }
            
        }
        reverse(right.begin(),right.end());    
        int sum=0;       
        for(int i=0;i<n;i++)
        {
            sum=sum+min(left[i],right[i])-height[i];
        }
        
        return sum;
    }
};


//Method-2 : 


class Solution 
{
public:
    int trap(vector<int>& height) 
    {

        int ans=0;
        int n=height.size();
        
        int left=0;
        int right=n-1;
        int left_max=0;
        int right_max=0;
        
        while(left<right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=left_max)
                {
                    left_max=height[left];
                }
                else
                {
                    ans=ans+left_max-height[left];
                }
                left++;
            }
            else
            {
                if(height[right]>=right_max)
                {
                    right_max=height[right];
                }
                else
                {
                    ans=ans+right_max-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
