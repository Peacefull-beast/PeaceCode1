class Solution {
public:
    set<vector<int>> st;

    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int ind) {
        if (ind == nums.size()) {
            if (temp.size() >= 2) {
                if (st.find(temp) == st.end()) {
                    ans.push_back(temp);
                    st.insert(temp);
                }
            }
            return;
        }

        if (temp.empty() || nums[ind] >= temp.back()) {
            temp.push_back(nums[ind]);
            solve(nums, ans, temp, ind + 1);
            temp.pop_back();
        }

        solve(nums, ans, temp, ind + 1);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, ans, temp, 0);
        return ans;
    }
};
