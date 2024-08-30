#include <stack>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string p = "";
        stringstream ss(path);
        string token;


        while (getline(ss, token, '/')) 
        {
            if (token == "" || token == ".")
                continue;
            else if (token == "..") 
            {
                if (!st.empty()) 
                    st.pop();
            } 
            else 
                st.push(token);

        }

        string ans = "";
        while (!st.empty()) 
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};
