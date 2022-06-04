class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
	if (digits.size()==0) return res;
	string table[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	string ans;
	backtrack(table, digits, 0, ans);
	return res;
    }

    void backtrack(string table[], string& digits, int i, string& ans) {
	if (i==digits.size()) {
	    res.emplace_back(ans);
	    return;
	}
	string temp = table[digits[i]-'2'];
	for (int j=0; j<temp.size(); ++j) {
	    ans += temp[j];
	    backtrack(table, digits, i+1, ans);
	    ans.pop_back();
	}
    }
};
