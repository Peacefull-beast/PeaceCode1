class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        int n = arr.size(), cur = arr[0];
        vector<int> result(n, cur);
        for(int i = 1; i < n; i++)
            result[i] = cur ^ arr[i], cur = arr[i];
        return result;
    }
};