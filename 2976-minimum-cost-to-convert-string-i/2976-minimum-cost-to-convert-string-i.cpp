class Solution {
public:
    void fill(vector<char>& ori, vector<char>& cha, vector<int>& cost, vector<vector<long long>>& dist) {
        int n = ori.size();
        
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) {
                    dist[i][j] = 0; 
                } else {
                    dist[i][j] = LLONG_MAX; 
                }
            }
        }

        // Fill in the initial distances based on the given conversion rules
        for (int i = 0; i < n; i++) {
            int s = ori[i] - 'a';
            int d = cha[i] - 'a';
            dist[s][d] = min(dist[s][d], (long long)cost[i]);
        }

        // Floyd-Warshall algorithm to find the minimum distance between all pairs of characters
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        fill(original, changed, cost, dist); 
        long long ans = 0;

        // Calculate the minimum cost to convert source to target
        for (int i = 0; i < n; i++) {
            int s = source[i] - 'a';
            int d = target[i] - 'a';
            if (s == d)
                continue;
            else {
                if (dist[s][d] == LLONG_MAX)
                    return -1; // No valid conversion path
                ans += dist[s][d];
            }
        }

        return ans;
    }
};
