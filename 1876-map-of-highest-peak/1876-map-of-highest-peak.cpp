#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;  
                }
            }
        }
        
        vector<int> nr = {-1, 0, 1, 0}; 
        vector<int> nc = {0, -1, 0, 1};  
        
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int currHeight = ans[row][col];
            q.pop();
            
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + nr[i];
                int ncol = col + nc[i];
                
                bool cond1 = nrow >= 0 && ncol >= 0 && nrow < n && ncol < m;
                
                if (cond1 && ans[nrow][ncol] == -1) 
                {
                    ans[nrow][ncol] = currHeight + 1;  
                    q.push({nrow, ncol});  
                }
            }
        }
        
        return ans;
    }
};
