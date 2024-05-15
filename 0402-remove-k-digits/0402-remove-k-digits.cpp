
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(char digit : num) {
            while(k > 0 && !st.empty() && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        // Remove remaining k digits if needed
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Construct the result string from stack
        string result = "";
        while(!st.empty()) {
            result += st.top() ;
            st.pop();
        }
        
        int endi = 0;
        for(int i = result.size()-1; i>=0; i--)
        {
            if(result[i] != '0')
            {
                endi = i;
                break;
            }
        }
        
        string ans = result.substr(0,endi+1);
        reverse(ans.begin(), ans.end());
        if(ans == "") return "0";
        else return ans;
    }
};
        
        