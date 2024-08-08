class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        int step = 0;
        int nums = rows*cols;
        
        vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}}; //E,S,W,N
        int d = 0;
        vector<vector<int>>res;
        res.push_back({r,c});
        while(res.size() != rows*cols)
        {
            if(d == 0 || d == 2)
                step++;
            
            for(int cnt = 0; cnt < step; cnt++)
            {
                r += dir[d].first;
                c += dir[d].second;
                
                bool cond = (r >= 0) && (c >= 0) && (r < rows) && (c < cols);
                
                if(cond)
                {
                    res.push_back({r,c});
                    
                }
            }
            d = (d+1)%4;   
        }
        
        return res;
        
    }
};