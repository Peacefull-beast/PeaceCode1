class Solution {
public:
    // void flip_row(vector<vector<int>>& grid, int row, int size) {
    //     for (int i = 1; i < size; i++) 
    //     {
    //         if(grid[row][i] == 0)
    //             grid[row][i] = 1;
    //         else
    //             grid[row][i] = 0;
    //         // cout<<grid[row][i]<<"   ";
    //     }
    // }
    
//     void flip_col(vector<vector<int>>& grid, int col, int size) {
//         for (int i = 0; i < size; i++) {
//             if(grid[i][col] == 0)
//                 grid[i][col] = 1;
//             else
//                 grid[i][col] = 0; 
//         }
//     }
    
    // int scr(vector<vector<int>>& grid, int row, int size) {
    //     int scre = 0;
    //     for (int i = size - 1; i >= 0; i--) {
    //         int temp = 1 << i;
    //         temp = temp * grid[row][i];
    //         scre+=temp;
    //     }
    //     return scre;
    // }
    
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) 
            {
                for(int j = 0; j<m; j++)
                grid[i][j] = 1 - grid[i][j];
            }
        }
        
        for (int col = 1; col < m; col++) {
            int cnt_0 = 0, cnt_1 = 0;
            for (int row = 0; row < n; row++) {
                if (grid[row][col] == 0) {
                    cnt_0++;
                } else {
                    cnt_1++;
                }
            }
            if (cnt_0 > cnt_1) 
            {
                for(int i = 0; i<n; i++)
                    grid[i][col] = 1 - grid[i][col];
            }
        }
        
        int score = 0;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j<m; j++)
            {
                int value = grid[i][j] *pow(2,(m-j-1)) ;
                score+=value;
            }
        }
        
        return score;
    }
};