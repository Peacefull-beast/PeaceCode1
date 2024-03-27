class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>,  vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;


        pq.push({0,{0,0}});

        vector<int> nrow = {-1, 0, 1, 0};
        vector<int> ncol  = {0, -1, 0 ,1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;


            if(row == n-1 && col == m-1)
            return diff;
            for(int i = 0; i<4; i++)
            {
                int newRow = row + nrow[i];
                int newCol = col + ncol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
                {
                    int newdiff = max(abs(heights[newRow][newCol] - heights[row][col]), diff);

                    if(newdiff < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = newdiff;
                        pq.push({newdiff,{newRow,newCol}});
                    }

                }
            }
        }
        return 0;
    }
};