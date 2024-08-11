class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>mp; //node->{node,dist}
    vector<int>nodes;
    Graph(int n, vector<vector<int>>& edges) 
    {
        nodes.resize(n);
        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];
            int d = e[2];
            
            mp[u].push_back({v,d});
        }
    }
    
    void addEdge(vector<int> e) 
    {
        int u = e[0];
        int v = e[1];
        int d = e[2];

        mp[u].push_back({v,d});    
    }
    
    int shortestPath(int node1, int node2) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        unordered_map<int, int> dist;

        for (int i=0; i<nodes.size(); i++) {
            dist[i] = INT_MAX;
        }

        pq.push({0, node1}); // distance, node
        dist[node1] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& neighbor : mp[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */