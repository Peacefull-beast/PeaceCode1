class Solution {
public:
    vector<int> NSR(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NSL(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int solve(vector<int>& height) {
        vector<int> nsr = NSR(height);
        vector<int> nsl = NSL(height);
        int n = height.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = width * height[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '0')
                    height[col] = 0;
                else
                    height[col] += 1;
            }
            maxArea = max(maxArea, solve(height));
        }

        return maxArea;
    }
};
