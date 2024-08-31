#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0); 
        queue<int> q;     

        
        q.push(0);
        vis[0] = 1;
        int vis_rooms = 1; 

        while (!q.empty()) {
            int room = q.front();
            q.pop();

            
            for (auto k : rooms[room]) {
                if (vis[k] == 0) {
                    q.push(k);
                    vis[k] = 1;
                    vis_rooms++;

                    
                    if (vis_rooms == n)
                        return true;
                }
            }
        }

        
        return vis_rooms == n;
    }
};
