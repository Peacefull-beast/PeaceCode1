class Solution {
public:
    vector<vector<int>> generateMatrix(int n1) {
        vector<vector<int>>matrix(n1, vector<int>(n1,0));
        int num = 1;
        
        
        int n = n1;
        int m = n1;
        
        int top = 0;
        int right = m - 1;
        int left = 0;
        int down = n - 1;
        
        
        
        while(num <= n * m)
        {
            for(int i = left; i <= right ; i++)
            {
                matrix[top][i] = num;
                num++;
            }
            
            top++;
            
            for(int j = top; j <= down ; j++)
            {
                matrix[j][right] = num;
                num++;
            }
            
            right--;
            
            for(int i = right; i >= left ; i--)
            {
                matrix[down][i] = num;
                num++;
            }
            
            down--;
            
            for(int j = down; j >= top ; j--)
            {
                matrix[j][left] = num;
                num++;
            }
            
            left++;
        }
        return matrix;
    }
};