
class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.length();
        vector<pair<string, int>> stk;
        int i = 0;

        while (i < n) 
        {
            if (s[i] == '(') 
            {
                stk.push_back({"(", 1});
                i++;
            } 
            else if (s[i] == ')') 
            {
                i++;
                int mul = 0;
                while (i < n && isdigit(s[i])) 
                {
                    mul = (mul * 10) + (s[i] - '0');
                    i++;
                }
                if (mul == 0) mul = 1;

                vector<pair<string, int>> temp;
                while (!stk.empty() && stk.back().first != "(") 
                {
                    stk.back().second *= mul;
                    temp.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                for (auto &p : temp) 
                {
                    stk.push_back(p);
                }
            } 
            else if (isupper(s[i])) 
            {
                string el = "";
                el += s[i++];
                while (i < n && islower(s[i])) {
                    el += s[i++];
                }
                int mul = 0;
                while (i < n && isdigit(s[i])) {
                    mul = (mul * 10) + (s[i] - '0');
                    i++;
                }
                if (mul == 0) mul = 1;
                stk.push_back({el, mul});
            }
        }

        unordered_map<string, int> mp;
        for (auto &p : stk) {
            if (p.first != "(") {
                mp[p.first] += p.second;
            }
        }

        vector<pair<string, int>> elements(mp.begin(), mp.end());
        sort(elements.begin(), elements.end());

        string ans = "";
        for (auto &p : elements) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }

        return ans;
    }
};

