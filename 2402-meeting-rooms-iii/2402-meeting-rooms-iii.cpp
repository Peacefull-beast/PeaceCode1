#define ll long long 
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        
        map<int,int>booked;             //booked room
        
        auto compare = [](const pair<ll, int>a, const pair<ll, int>b)
        {
            if(a.first == b.first)
                return a.second > b.second; //fi end time is same lower room id is prefrred
            else 
                return a.first > b.first;  // other wise lower end time is preferred
        };
        priority_queue<pair<ll, int>, vector<pair<ll,int>>, decltype(compare)> pq; //end time, room id of occ meet
        priority_queue<int, vector<int>, greater<int>> freeRooms; // free rooms
        
        
        for(int  i = 0; i<n; i++)
            freeRooms.push(i);
        
        
        sort(meetings.begin(), meetings.end());
        
        for(auto& meet: meetings)
        {
            ll start = meet[0];
            ll end = meet[1];
            
            while(!pq.empty()  && pq.top().first <= start) //some rooms are occupied,
            {                                            //check if any room can be freed 
                freeRooms.push(pq.top().second);           //and push it into freerooms
                pq.pop();
            }
            
            if(!freeRooms.empty())
            {
                booked[freeRooms.top()]++;               //if free room avail, room booked and meet held
                pq.push({end, freeRooms.top()});
                freeRooms.pop();
            }
            
            else
            {
                booked[pq.top().second]++;                  //no free room available
                auto p = pq.top();                          // find room with min end time in occupied room
                pq.pop();                                   //hold meetin that room
                pq.push({p.first + end - start, p.second});  // with time difference of that meet and room id
            }
        }
        
        int maxroom = 0;
        int meetroom = -1;
        for(auto p : booked)
        {
            if(p.second > maxroom)
            {
                maxroom = p.second;
                meetroom = p.first;
            }
        }
        
        return meetroom;
    }
};