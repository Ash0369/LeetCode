class Solution 
{
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        #define ll long long
        #define pii pair<int,int>
        priority_queue<pii,vector<pii>,greater<pii>>beg;
        priority_queue<pii,vector<pii>,greater<pii>>end;
        
        int left=0;
        for(;left<candidates;left++)
        {
            beg.push({costs[left],left});
        }
        int n=costs.size();
        int right=max(left,n-candidates);
        for(int i=right;i<n;i++)
        {
            end.push({costs[i],i});
        }
        right--;
        ll int ans=0;
        for(int i=0;i<k;i++)
        {
            if(beg.empty() || end.empty())
            {
                while(i<k)
                {
                    if(!end.empty())
                    {
                        ans+=end.top().first;
                        end.pop();
                        i++;
                    }
                    else
                    {
                        ans+=beg.top().first;
                        beg.pop();
                        i++;
                    }
                    
                }
                break;
            }
            auto a=beg.top();
            auto b=end.top();
            
            if(a.first!=b.first)
            {
                if(a.first<b.first)
                {
                    ans+=a.first;
                    beg.pop();
                    if(left<=right)
                    {
                        beg.push({costs[left],left});
                        left++;
                    }
                }
                else if(a.first>b.first)
                {
                    ans+=b.first;
                    end.pop();
                    if(right>=left)
                    {
                        end.push({costs[right],right});
                        right--;
                    }
                }
            }
            else
            {
                
                if(a.second<b.second)
                {
                    ans+=a.first;
                    beg.pop();
                    if(left<=right)
                    {
                        beg.push({costs[left],left});
                        left++;
                    }
                }
                else if(a.second>b.second)
                {
                    ans+=b.first;
                    end.pop();
                    if(right>=left)
                    {
                        end.push({costs[right],right});
                        right--;
                    }
                }
                
            }
        }
        return ans;
    }
};
