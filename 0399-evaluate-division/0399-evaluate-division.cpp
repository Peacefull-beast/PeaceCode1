#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        
        // Building the graph
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double value = values[i];
            
            graph[u].push_back({v, value});
            graph[v].push_back({u, 1.0 / value});
        }
        
        vector<double> ans;
        
        // Processing each query
        for (auto& q : queries) {
            string u = q[0];
            string v = q[1];
            
            if (graph.find(u) == graph.end() || graph.find(v) == graph.end()) {
                ans.push_back(-1.0);
            } else if (u == v) {
                ans.push_back(1.0);
            } else {
                unordered_map<string, double> visited;
                ans.push_back(dfs(graph, u, v, visited));
            }
        }
        
        return ans;
    }
    
private:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, string u, string v, unordered_map<string, double>& visited) {
        if (u == v) return 1.0;
        visited[u] = 1.0;
        
        for (auto& neighbor : graph[u]) {
            string nextNode = neighbor.first;
            double value = neighbor.second;
            
            if (visited.find(nextNode) == visited.end()) {
                double result = dfs(graph, nextNode, v, visited);
                if (result != -1.0) {
                    return result * value;
                }
            }
        }
        
        return -1.0;
    }
};
