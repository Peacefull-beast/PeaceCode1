class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int x=matrix[0].size();
        // 
//         for(int i=0;i<x;i++)
//         {
//             for(int j=0;j<x;j++)
            
//                 cout<<matrix[i][j]<<"   ";
//             cout<<endl;
//         }
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<i;j++)
            
                swap(matrix[i][j],matrix[j][i]);      
        }
//         for(int i=0;i<x;i++)
//         {
//             for(int j=0;j<x;j++)
            
//                 cout<<matrix[i][j]<<"   ";
//             cout<<endl;
//         }
        for(int i=0;i<x;i++)
        {
                for(int j=0;j<x/2;j++)
                    swap(matrix[i][j],matrix[i][x-1-j]);
        }
//         for(int i=0;i<x;i++)
//         {
//             for(int j=0;j<x;j++)
            
//                 cout<<matrix[i][j]<<"   ";
//             cout<<endl;
//         }
        
        
    }
};