class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using P = pair<int, int>;
        unordered_map<int, vector<pair<int, int>>> mp;
        
        for (auto& t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            mp[u].push_back({v, w});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, k}); //dist from source, node
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto& nbr : mp[node]) {
                int adjnode = nbr.first;
                int wt = nbr.second;
                
                if (dist[adjnode] > d + wt) {
                    dist[adjnode] = d + wt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;
    }
};