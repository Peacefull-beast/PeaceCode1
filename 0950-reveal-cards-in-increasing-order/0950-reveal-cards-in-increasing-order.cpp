class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int>q;
        for(int i = 0; i<n; i++)
            q.push(i);
        
        vector<int>ans(n, -1);
        int i = 1;
        int plc = 0;
        while(q.empty() != true)
        {
            if(i%2 != 0)
            {
                int ind = q.front();
                ans[ind]  = deck[plc++]; 
                q.pop();
                
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            i++;
        }
        return ans;
    }
};