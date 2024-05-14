class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str = "";
        stack<int> st; // Changed to stack of indices to keep track of '(' positions
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                str += s[i];
            } else if (s[i] == '(') {
                st.push(str.length()); // Push the index of '(' to stack
                str += s[i];
            } else if (s[i] == ')' && !st.empty()) {
                st.pop(); // Pop the index of corresponding '('
                str += s[i];
            }
        }

        // Remove unpaired '(' at indices left in the stack
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            str = str.substr(0, idx) + str.substr(idx + 1);
        }

        return str;
    }
};
