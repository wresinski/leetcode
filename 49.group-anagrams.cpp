#include <unordered_map>
class Solution {
public:
    // 计数哈希
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	auto hashfunc = [](const array<int, 26>& arr)->size_t {
	    return accumulate(arr.begin(), arr.end(), 0, [](size_t acc,int a) {
		return (acc<<1)^hash<int>()(a);
	    });
	};

	vector<vector<string>> res;
	unordered_map<array<int, 26>, vector<string>, decltype(hashfunc)> map(0/*初始bucket数*/, hashfunc/*哈希函数*/);
	for (string& s : strs) {
	    array<int, 26> key{};
	    for (char& c : s) key[c-'a']++;
	    map[key].emplace_back(s);
	}
	for (auto iter=map.begin(); iter!=map.end(); ++iter) {
	    res.emplace_back(iter->second);
	}
	return res;
    }
    /*
    // 排序哈希
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	unordered_map<string, vector<string>> map;
	for (string& s : strs) {
	    string key = s;
	    sort(key.begin(), key.end());
	    map[key].emplace_back(s);
	}
	for (auto iter=map.begin(); iter!=map.end(); ++iter) {
	    res.emplace_back(iter->second);
	}
	return res;
    }
    */
};
