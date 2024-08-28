#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> vis; 
        unordered_set<int> fbd(forbidden.begin(), forbidden.end()); 
        
        
        queue<pair<int, bool>> q;
        q.push({0, false});
        vis.insert(0);
        
        int maxPos = 6000;  
        int ans = 0;
        
        while (!q.empty()) 
        {
            int sz = q.size();
            while (sz--) 
            {
                int n = q.front().first;
                bool d = q.front().second;
                q.pop();
                
                if (n == x) return ans;
                
                int o1 = n + a;
                if (o1 < maxPos && fbd.find(o1) == fbd.end() && vis.find(o1) == vis.end()) 
                {
                    q.push({o1, false});
                    vis.insert(o1);
                }
                
                int o2 = n - b;
                if (!d && o2 >= 0 && fbd.find(o2) == fbd.end() && vis.find(o2) == vis.end()) 
                {
                    q.push({o2, true});
                    
                }
            }
            ans++;
        }
        return -1;
    }
};
