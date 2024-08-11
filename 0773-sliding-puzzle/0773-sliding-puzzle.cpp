class Solution {
public:
    int n = 2;
    int m = 3;
    
    vector<int> nr = {-1, 0, 1, 0};
    vector<int> nc = {0, -1, 0, 1};
    string target = "123450";
    
    bool check(const string& board)
    {
        return board == target;
    }

    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string start = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        
        if (check(start)) return 0;
        
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            string curr = q.front().first;
            int moves = q.front().second;
            q.pop();
            
            int zeroPos = curr.find('0');
            int r = zeroPos / 3;
            int c = zeroPos % 3;
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + nr[i];
                int ncol = c + nc[i];
                
                
                bool cond = nrow >= 0 && ncol >= 0 && nrow < 2 && ncol < 3;
                if (cond) 
                {
                    string next = curr;
                    swap(next[zeroPos], next[nrow * 3 + ncol]);
                    
                    if (check(next)) return moves + 1;
                    
                    if (visited.find(next) == visited.end()) 
                    {
                        q.push({next, moves + 1});
                        visited.insert(next);
                    }
                }
            }
        }
        
        return -1;
    }
};