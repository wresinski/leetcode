class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = 0;
        for (const vector<char>& row : board)
            for (const char& c : row) {
            if (c == word[0])
            h += 1;
            else if (c == word.back())
            h -= 1;
        }
        //剪枝，用少的那个。估计是可以剪掉那个刚好很多重复头元素的
        if (h > 0) reverse(word.begin(), word.end());
	int m = board.size();
	int n = board[0].size();
	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
	        if (board[i][j]==word[0]) {
		    board[i][j] = '0';
		    if (backtrace(board, word, i, j, 1)) return true;
		    board[i][j] = word[0];
		}
	    }
	}
	return false;
    }
    bool backtrace(vector<vector<char>>& board, string& word, int i, int j, int x) {
	if (x==word.size()) {
	    return true;
	}
	int m = board.size();
	int n = board[0].size();
	if (i>0&&board[i-1][j]==word[x]) {
	    board[i-1][j] = '0';
	    if (backtrace(board, word, i-1, j, x+1)) return true;
	    board[i-1][j] = word[x];
	}
	if (j<n-1&&board[i][j+1]==word[x]) {
	    board[i][j+1] = '0';
	    if (backtrace(board, word, i, j+1, x+1)) return true;
	    board[i][j+1] = word[x];
	}
	if (i<m-1&&board[i+1][j]==word[x]) {
	    board[i+1][j] = '0';
	    if (backtrace(board, word, i+1, j, x+1)) return true;
	    board[i+1][j] = word[x];
	}
	if (j>0&&board[i][j-1]==word[x]) {
	    board[i][j-1] = '0';
	    if (backtrace(board, word, i, j-1, x+1)) return true;
	    board[i][j-1] = word[x];
	}
	return false;
    }
};
