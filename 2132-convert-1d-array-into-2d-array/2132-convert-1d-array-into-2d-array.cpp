class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
        vector<vector<int>>ans;
        if(original.size() != n*m)
        return ans;
        int ind = 0;
        while(ind < original.size())
        {
            vector<int>temp;
            for(int j=0; j<m; j++)
            {
                temp.push_back(original[ind]);
                ind++;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};