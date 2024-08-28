class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n=grid.size();
        int m=grid[0].size();


        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        priority_queue<vector<int>> pq;


        vector<int> nr = {-1, 0, 1, 0};
        vector<int> nc = {0, 1, 0, -1};

        if(grid[start[0]][start[1]]==0) return {};


        int p1 = pricing[0];
        int p2 = pricing[1];

        q.push({start[0],start[1]}); 
        dist[start[0]][start[1]]=0;


        int steps=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                if(grid[row][col] >= p1 && grid[row][col] <= p2 && grid[row][col] > 1)
                    {
                        pq.push({steps, grid[row][col], row, col});
                        if(pq.size() > k)
                        pq.pop();
                    }
                
                for(int i=0;i<4;i++) 
                {
                    int nrow=row+nr[i];
                    int ncol=col+nc[i];
                    bool cond1 = (nrow>=0) && (nrow<n) && (ncol>=0) && (ncol<m);
                    
                    if(cond1)
                    {
                        bool cond2 = (grid[nrow][ncol]!=0) && (dist[nrow][ncol]==-1);
                        if(cond2)
                        {
                            dist[nrow][ncol]=steps+1;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
            steps++;
        }

        vector<vector<int>> ans;
        while(pq.size() )
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());

        for(auto &x:ans) x={x[2],x[3]};
        return ans;

    }
};