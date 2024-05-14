class Solution {
public:
    vector<int> nextSmall(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmall(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> ns = nextSmall(heights);
        vector<int> ps = prevSmall(heights);
        
        int maxi = INT_MIN; 
        
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int w = ns[i] - ps[i] - 1;
            
            maxi = max(maxi, h * w);
        }
        return maxi;
    }
};