#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int K) 
    {
        string result = "";
        for (char c : s) {
            if (c != '-') {
                result += toupper(c);
            }
        }

        int n = result.length();
        for (int i = K; i < n; i += K) {
            result.insert(n - i, 1, '-');
        }

        return result;
    }
};
