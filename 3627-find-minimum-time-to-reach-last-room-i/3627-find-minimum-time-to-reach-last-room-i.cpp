#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}}); 

        vector<int> nr = {0, 1, 0, -1};
        vector<int> nc = {1, 0, -1, 0};

        vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
        minTime[0][0] = 0;

        while (!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == rows - 1 && y == cols - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int nx = x + nr[i];
                int ny = y + nc[i];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                    int newTime = max(time, moveTime[nx][ny]) + 1;

                    if (newTime < minTime[nx][ny]) {
                        minTime[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};
