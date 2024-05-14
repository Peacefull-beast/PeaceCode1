

class Solution {
public:
    bool bfs(vector<vector<char>>& board, const string& word, int row, int col, int ind) {
        if (ind == word.size())
            return true;

        vector<int> nr = {0, 1, 0, -1};
        vector<int> nc = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = row + nr[i];
            int ncol = col + nc[i];

            if (nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && board[nrow][ncol] == word[ind]) {
                board[nrow][ncol] = '#';
                bool ans = bfs(board, word, nrow, ncol, ind + 1);
                if (ans)
                    return true;
                board[nrow][ncol] = word[ind]; 
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, const string& word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    bool ans = bfs(board, word, i, j, 1);
                    if (ans)
                        return true;
                    board[i][j] = word[0]; 
                }
            }
        }

        return false;
    }
};
