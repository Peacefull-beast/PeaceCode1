#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>  // For std::pair
#include <bitset>

using namespace std;

class Solution {
public:
    bool areAllBitsSet(int number, int n) {
       
        int allOnesMask = (1 << n) - 1;
        
        return (number == allOnesMask);
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        unordered_set<string> visited;

        
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            pq.push({0, {i, mask}});
            visited.insert(to_string(i) + "," + to_string(mask));
        }
        
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second.first;
            int mask = pq.top().second.second;
            pq.pop();
            
            
            if (areAllBitsSet(mask, n))
                return dist;
            
            
            for (int nbr : graph[node]) {
                int newMask = mask | (1 << nbr);
                string state = to_string(nbr) + "," + to_string(newMask);

                
                if (visited.find(state) == visited.end()) {
                    visited.insert(state);
                    pq.push({dist + 1, {nbr, newMask}});
                }
            }
        }
        
        return -1; 
    }
};
