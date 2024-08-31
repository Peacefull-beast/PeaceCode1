#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    
    bool check(string &a, string &b) {
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i]) {
                ans++;
            }
        }
        return (ans == 1);
    }

    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;

        
        bool endInBank = false;
        int endidx = INT_MIN;
        for (const string& gene : bank) {
            if (gene == end) 
            {
                endidx = 
                endInBank = true;
                break;
            }
        }
        if (!endInBank) return -1;

        
        bool startInBank = false;
        for (const string& gene : bank) {
            if (gene == start) {
                startInBank = true;
                break;
            }
        }
        if (!startInBank) bank.push_back(start);

        bank.push_back(end);
        int n = bank.size();

        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(bank[i], bank[j])) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        // BFS to find the shortest path
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);

        
        int startIndex = find(bank.begin(), bank.end(), start) - bank.begin();
        int endIndex = find(bank.begin(), bank.end(), end) - bank.begin();

        q.push({0, startIndex});
        visited[startIndex] = true;

        while (!q.empty()) {
            int step = q.front().first;
            int num = q.front().second;
            q.pop();

            if (num == endIndex) return step;

            for (int nbr : mp[num]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({step + 1, nbr});
                }
            }
        }

        return -1; 
    }
};
