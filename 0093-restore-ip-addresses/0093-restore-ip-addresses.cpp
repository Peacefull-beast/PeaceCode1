class Solution {
public:
    void solve(string s, string temp, int ind, int part, vector<string>& ans) {
        
        if (part == 4 && ind == s.length()) 
        {
            ans.push_back(temp);
            return;
        }
        if (part == 4 || ind == s.length()) 
            return;
        
        for (int i = 1; i <= 3; i++) 
        {
            if (ind + i > s.length()) 
                break;
            string segment = s.substr(ind, i);
            int num = stoi(segment);
            if (num > 255 || (segment[0] == '0' && segment.length() > 1)) 
                break;
            
            string temp1 = temp;
            if (part > 0) {
                temp += ".";
            }
            temp += segment;
            solve(s, temp, ind + i, part + 1, ans);
            temp = temp1; 
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(s, "", 0, 0, ans);
        return ans;
    }
};
