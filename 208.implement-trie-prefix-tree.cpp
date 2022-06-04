class Trie {
public:
    Trie() : _end(false){
	memset(_children, 0, 26*sizeof(Trie*));
    }
    
    void insert(string word) {
	if (word.size()==0) {
	    _end = true;
	    return;
	}
	if (_children[word[0]-'a']==nullptr) {
	    _children[word[0]-'a'] = new Trie;
	}
	_children[word[0]-'a']->insert(word.substr(1, word.size()-1));
    }
    
    bool search(string word) {
	if (word.size()==0) {
	    if (_end) return true;
	    else return false;
	}
	if (_children[word[0]-'a']==nullptr) return false;
	return _children[word[0]-'a']->search(word.substr(1, word.size()-1));
    }
    
    bool startsWith(string prefix) {
	if (prefix.size()==0) return true;
	if (_children[prefix[0]-'a']==nullptr) return false;
	return _children[prefix[0]-'a']->startsWith(prefix.substr(1, prefix.size()-1));
    }

private:
    Trie* _children[26];
    bool _end;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
