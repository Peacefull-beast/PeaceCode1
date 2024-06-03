class Solution {
public:
    void solve(vector<vector<int>> &image, queue<pair<int,int>>q, int new_col, int or_col)
    {
        int n = image.size();
        int m = image[0].size();
        vector<int>drow = {-1, 0 ,1, 0};
        vector<int>dcol = {0, -1, 0, 1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = new_col;
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+ dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == or_col)
                {
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int p) 
    {
        if(image[x][y] == p)
            return image;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>>q;
        q.push({x,y});
        solve(image, q, p, image[x][y]);
        return image;
        
    }
};