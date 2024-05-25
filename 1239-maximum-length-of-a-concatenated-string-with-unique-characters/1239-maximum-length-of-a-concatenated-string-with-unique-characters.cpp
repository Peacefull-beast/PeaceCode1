class Solution {
public:
    bool eligible(string s, vector<bool> ch) {
        for (char letter : s)
        {
            if (ch[letter - 'a'] == true)
                return false;
            ch[letter - 'a'] = true;
        }    
        
        return true;
    }

    int solve(int ind, vector<string>& arr, vector<bool>& ch) {
        if (ind == arr.size())
            return 0;

        int npick = solve(ind + 1, arr, ch);
        int pick = 0;
        if (eligible(arr[ind], ch)) {
            for (char letter : arr[ind])
                ch[letter - 'a'] = true;
            pick = arr[ind].length() + solve(ind + 1, arr, ch);
            for (char letter : arr[ind])
                ch[letter - 'a'] = false;
        }

        return max(pick, npick);
    }

    int maxLength(vector<string>& arr) {
        vector<bool> ch(26, false);
        return solve(0, arr, ch);
    }
};
