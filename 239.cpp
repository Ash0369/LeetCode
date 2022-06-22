//Method-1 using Dequeue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int>dq; //Will store max value
        vector<int>res;
        for(int i=0;i<k;i++)
        {
           
            while(!dq.empty()&& nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for(int i=k;i<(nums.size());i++)
        {
            
            while(!dq.empty() && (i-dq.front())>=k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
            
          
        }
       
        return res;
        
    }
};


//Method-2 using MultiSet
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int>vec;
        multiset<int>wind;
        int n=nums.size();
        int max_num=INT_MIN;
        for(int i=0;i<k;i++)
        {
            wind.insert(nums[i]);
        }
        vec.push_back(*(wind.rbegin())); //rbegin() gives pointer at last element(which is maximum) of the set 
        int drop=0;
        for(int i=k;i<n;i++)
        {
            auto pos=wind.find(nums[drop]);
            wind.erase(pos);
            drop++;
            wind.insert(nums[i]);

            vec.push_back(*(wind.rbegin()));
        }

        return vec;
        
    }
};
