#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        reverse(board.begin(), board.end()); 

        queue<pair<int, int>> q; 
        unordered_set<int> vis; 

        q.push({0, 1}); 
        vis.insert(1);

        while (!q.empty()) 
        {
            int sz = q.size();
            while (sz--) 
            {
                int num = q.front().second;
                int step = q.front().first;
                q.pop();

                if (num == n * n) 
                    return step; 

                for (int i = 1; i <= 6; i++) 
                {
                    int next = num + i;
                    if (next > n * n) 
                        break; 

                    int row = (next - 1) / n;
                    int col = (next - 1) % n;

                   
                    if (row % 2 == 1)
                        col = n - 1 - col;

                    int nextNum = board[row][col] == -1 ? next : board[row][col];

                    if (vis.find(nextNum) == vis.end()) 
                    {
                        vis.insert(nextNum);
                        q.push({step + 1, nextNum});
                    }
                }
            }
        }
        return -1; 
    }
};
