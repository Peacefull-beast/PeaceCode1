class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int n = temp.size();
        vector<int> ans(n, 0);

        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                ans[i] = 0;
                st.push({temp[i], i});
            }
            else if(temp[i] >= st.top().first) {
                while(!st.empty() && st.top().first <= temp[i])
                    st.pop();
                if(st.empty())
                    ans[i] = 0;
                else
                    ans[i] = st.top().second - i;
                st.push({temp[i], i});
            }  
            else {
                ans[i] = st.top().second - i; 
                st.push({temp[i], i});
            } 
        }

        return ans;
    }
};
