#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        unordered_set<int> visited;
        
        q.push(start);
        visited.insert(start);
        
        int ops = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int n = q.front();
                q.pop();
                
                for (int i = 0; i < nums.size(); i++) {
                    int a = n + nums[i];
                    int b = n - nums[i];
                    int c = n ^ nums[i];

                    if (a == goal || b == goal || c == goal)
                        return ops + 1;

                    if (a >= 0 && a <= 1000 && visited.find(a) == visited.end()) {
                        q.push(a);
                        visited.insert(a);
                    }
                    if (b >= 0 && b <= 1000 && visited.find(b) == visited.end()) {
                        q.push(b);
                        visited.insert(b);
                    }
                    if (c >= 0 && c <= 1000 && visited.find(c) == visited.end()) {
                        q.push(c);
                        visited.insert(c);
                    }
                }
            }
            ops++;
        }
        return -1;
    }
};
