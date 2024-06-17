class Solution {
public:
    string removeStars(string s) {
        vector<char> result;

        for (char ch : s) {
            if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(ch);
            }
        }

        return string(result.begin(), result.end());
    }
};
