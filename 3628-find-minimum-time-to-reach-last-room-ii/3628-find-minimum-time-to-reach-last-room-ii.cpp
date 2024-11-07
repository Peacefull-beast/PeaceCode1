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

        vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));

        vector<int> nr = {0, 1, 0, -1};
        vector<int> nc = {1, 0, -1, 0};

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0, 0}); // {time, x, y, prev}

        while (!pq.empty()) {
            int time = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            int prev = pq.top()[3];
            pq.pop();

            if (x == rows - 1 && y == cols - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int nx = x + nr[i];
                int ny = y + nc[i];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                    int additionalTime = (prev == 0) ? 0 : 1;
                    int newTime = max(time, moveTime[nx][ny]) + 1 + additionalTime;

                    if (newTime < minTime[nx][ny]) {
                        minTime[nx][ny] = newTime;
                        pq.push({newTime, nx, ny, (additionalTime + 1) % 2});
                    }
                }
            }
        }

        return -1;
    }
};
