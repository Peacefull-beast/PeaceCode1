class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        unordered_map<int, vector<pair<int,int>>>mp;//node-> {wt,node}
        for(int i=0; i<points.size(); i++)
        {
            vector<int>p1 = points[i];
            for(int j=0; j<points.size(); j++)
            {
                if(i == j)
                    continue;
                
                else
                {
                    vector<int>p2 = points[j];
                    int x = abs(p2[0] - p1[0]);
                    int y = abs(p2[1] - p1[1]);
                    mp[i].push_back({x+y, j});
                    mp[j].push_back({x+y, i});
                }
            }
        }
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        
        pq.push({0,0});//wt,node
        
        vector<bool>inMST(n, false);
        
        int sum = 0;
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            
            pq.pop();
            
            if(inMST[node])
                continue;
            
            inMST[node] = true;
            sum += wt;
            
            for(auto n:mp[node])
            {
                int nbr = n.second;
                int nbrwt = n.first;
                
                if(inMST[nbr] == false)
                    pq.push({nbrwt,nbr});
            }
        }
        return sum;
        
    }
};