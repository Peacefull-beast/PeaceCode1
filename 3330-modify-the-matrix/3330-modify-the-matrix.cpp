class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int m =matrix[0].size();
        for(int i=0;i<m;i++){
            int maxi = INT_MIN;

            for(int j=0;j<n;j++){
                // if(matrix[i][j]==-1)matrix[i][j]=maxi;
                maxi = max(maxi, matrix[j][i]);
            }
            for(int j=0;j<n;j++){
                if(matrix[j][i]==-1)matrix[j][i]=maxi;
                // maxi = max(maxi, matrix[j][i]);
            }
            
        }
        return matrix;
    }
};