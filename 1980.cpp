string s;
void find_different(map<string,int>&mp,string formed,int n)
{
    if(mp.find(formed)==mp.end())
    {
        s=formed;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(formed[i]=='0')
        {
            formed[i]='1'; //Turning on ith bit and calling recurssion
            find_different(mp,formed,n);
            formed[i]='0';
        }  
    }
}
class Solution 
{
public:
    string findDifferentBinaryString(vector<string>&nums) 
    {
        map<string,int>mp;
        string formed;
        for(int i=0;i<nums.size();i++)
        {
            formed.push_back('0');
            mp[nums[i]]++;
        }
        find_different(mp,formed,nums.size());
        return s;
    }
};
