class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int top = 0;
        int right = m - 1;
        int left = 0;
        int down = n - 1;
        
        vector<int> ans;
        
        while(ans.size() < n * m)
        {
            for(int i = left; i <= right && ans.size() < n * m; i++)
                ans.push_back(matrix[top][i]);
            
            top++;
            
            for(int j = top; j <= down && ans.size() < n * m; j++)
                ans.push_back(matrix[j][right]);
            
            right--;
            
            for(int i = right; i >= left && ans.size() < n * m; i--)
                ans.push_back(matrix[down][i]);
            
            down--;
            
            for(int j = down; j >= top && ans.size() < n * m; j--)
                ans.push_back(matrix[j][left]);
            
            left++;
        }
        
        return ans;
    }
};
