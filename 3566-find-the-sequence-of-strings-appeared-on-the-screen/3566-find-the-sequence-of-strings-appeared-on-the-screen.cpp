#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string t = "a"; // Start with "a"
        ans.push_back(t);

        int ind = 0;
        while (t != target) {
            
            while (t[ind] != target[ind]) {
                t[ind]++;
                ans.push_back(t);
            }
            ind++; 
            if (ind < target.size()) {
                t += "a"; 
                ans.push_back(t);
            }
        }
        
        return ans;
    }
};
