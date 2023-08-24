class Solution 
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        int n=words.size();
        vector<string>ans;
        
        for(int i=0;i<n;i++)
        {
            int ws=0;
            int ele=0;
            vector<string>temp;
            while(i<n)
            {
                //cout<<"S"<<endl;
                if(ws+words[i].size()<=maxWidth)
                {
                    ws+=words[i].size()+1;
                    ele++;
                    words[i].push_back(' ');
                    temp.push_back(words[i]);
                    i++;
                }
                else
                {
                    
                    i--;
                    break;
                }
            }
            temp.back().pop_back();
            ws--;
            //cout<<temp.back()<<2<<endl;
            int gap=maxWidth-ws;
            int space=gap/max(1,ele-1);
            int e=gap%max(1,ele-1);
            string a="";
            if(i>=n-1)
            {
                //completed so as left
                int left=maxWidth;
                for(auto x:temp)
                {
                    a+=x;
                    left-=x.size();
                }
                while(left>0)
                {
                    a.push_back(' ');
                    left--;
                }
                ans.push_back(a);
                break;
            }
            //cout<<e<<endl;
            for(int i=0;i<temp.size();i++)
            {
                a=a+temp[i];
                if(gap>0 && i<temp.size()-1)
                {
                    for(int j=0;j<space;j++)
                    {
                        a.push_back(' ');
                    }
                    if(e>0)
                    {
                        a.push_back(' ');
                        e--;
                        gap--;
                    }
                    gap=gap-space;
                }
                else if(i==temp.size()-1)
                {
                    for(int j=0;j<gap;j++)
                    {
                        a.push_back(' ');
                    }
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};
