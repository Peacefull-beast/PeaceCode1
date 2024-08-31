class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0; 
        int n = pushed.size();
        stack<int> st;

        while (i < n || !st.empty()) 
        {
            if (!st.empty() && st.top() == popped[j]) 
            {
                st.pop();
                j++;
            } 
            else if (i < n) 
            {
                st.push(pushed[i]);
                i++;
            } 
            else 
                return false;
        }

        return st.empty(); 
        }
};
