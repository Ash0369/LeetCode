//Method-1 : Using Linked List

struct List_Node 
{
    int userId;
    int tweetId;
    List_Node *next;
    List_Node() : userId(0),tweetId(0), next(nullptr) {}
    List_Node(int x,int y) : userId(x),tweetId(y), next(nullptr) {}
    List_Node(int x,int y,List_Node *next) : userId(x),tweetId(y),next(next) {}
};
class Twitter 
{
public:
    List_Node *dummy_head=new List_Node(-1,-1);
    map<int,set<int>>mp;
    Twitter() 
    {
        dummy_head->next=NULL;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        List_Node *temp=dummy_head->next;
        List_Node *tweet=new List_Node(userId,tweetId);
        dummy_head->next=tweet;
        tweet->next=temp;
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        //Making user follow itself
        if(mp[userId].find(userId)==mp[userId].end())
        {
            mp[userId].insert(userId);
        }
        List_Node *temp=dummy_head->next;
        vector<int>result;
        while(temp!=NULL)
        {
            if(mp[userId].find(temp->userId)!=mp[userId].end())
            {
                if(result.size()<10)
                {
                    result.push_back(temp->tweetId);
                }
                else
                {
                    break;
                }
            }
            temp=temp->next;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) 
    {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        mp[followerId].erase(followeeId);
    }
};

//Methd-2 : Using Priority Queue

class Twitter 
{
public:

    priority_queue<pair<int,pair<int,int>>>pq;
    priority_queue<pair<int,pair<int,int>>>back_up;
    int k;
    map<int,set<int>>mp;
    Twitter() 
    {
        k=0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        pq.push(make_pair(k,make_pair(userId,tweetId)));
        k++;
    }
    
    vector<int>getNewsFeed(int userId) 
    {

        //If user not follow himself
        mp[userId].insert(userId);
        int count=0;
        vector<int>result;
        while(count<10 && !pq.empty())
        {
            if(mp[userId].find(pq.top().second.first)!=mp[userId].end())
            {
                result.push_back(pq.top().second.second);
                count++;
            }
            back_up.push(pq.top());
            pq.pop();
            
        }
        while(!back_up.empty())
        {
            pq.push(back_up.top());
            back_up.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) 
    {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        mp[followerId].erase(followeeId);
    }
};
