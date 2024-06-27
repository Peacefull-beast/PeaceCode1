class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> v1 = edges[0];
        vector<int> v2 = edges[1];
        if(v1[0] == v2[0])
            return v1[0];
        if(v1[0] == v2[1])
            return v1[0];
        else
            return v1[1];

    }
};