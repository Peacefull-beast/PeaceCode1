class Solution {
public:
    int fn(const string &s)
    {
        int hr = stoi(s.substr(0, 2));
        int min = stoi(s.substr(3, 2));

        return hr * 60 + min; 
    }
    
    int findMinDifference(vector<string>& timePoints) 
    {
        set<int> st; 

        for(auto& t : timePoints)
        {
            int minutes = fn(t); 
            if(st.find(minutes) != st.end())
                return 0;
            st.insert(minutes);
        }

        int mini = INT_MAX;
        int prev = -1;
        int first = -1, last = -1;

        for(auto it : st)
        {
            if(prev != -1)
                mini = min(mini, it - prev);
            else
                first = it; 
            
            prev = it; 
            last = it; 
        }
        mini = min(mini, 1440 - last + first);

        return mini;
    }
};
