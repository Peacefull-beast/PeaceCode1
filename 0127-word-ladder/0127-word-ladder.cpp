class Solution {
public:
    int n;

    bool check(string &t1, string &t2) {
        int diff = 0;
        for (int i = 0; i < t1.size(); i++) {
            if (t1[i] != t2[i]) {
                diff++;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }

    int bfs(unordered_map<int, vector<int>> &mp, int srt, int end) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({1, srt});  
        vector<int> vis(n, 0);

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = 1;

            if (node == end)
                return dist;

            for (auto nbr : mp[node]) {
                if (!vis[nbr]) {
                    pq.push({dist + 1, nbr});
                }
            }
        }
        return 0;  
    }

    int ladderLength(string beginWord, string endWord, vector<string>& word) 
    {
        unordered_map<int, vector<int>> mp;
        word.push_back(beginWord);
        int endIdx = -1;

        for (int i = 0; i < word.size(); i++) 
        {
            if (word[i] == endWord) 
            {
                endIdx = i;
            }
        }

        if (endIdx == -1) return 0;  

        n = word.size();
        int srt = n - 1;

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            { 
                if (check(word[i], word[j])) 
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        return bfs(mp, srt, endIdx);
    }
};
