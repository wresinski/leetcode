class LRUCache {
public:
    struct DListNode {
	int key, value;
	DListNode* pre;
	DListNode* next;
	DListNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
	DListNode(int _key, int _value) : key(_key), value(_value), pre(nullptr), next(nullptr) {}
    };

    LRUCache(int capacity) {
	_max = capacity;
	_head = new DListNode;
	_tail = new DListNode;
	_head->next = _tail;
	_tail->pre = _head;
    }
    
    int get(int key) {
	auto iter = _map.find(key);
	if (iter!=_map.end()) { // 存在则移动到链表头部并返回值
	    moveToHead(iter->second);
	    return iter->second->value;
	}
	else { // 不存在
	    return -1;
	}
    }
    
    void put(int key, int value) {
	auto iter = _map.find(key);
	if (iter!=_map.end()) { //存在则移动到链表头部并改变值
	    moveToHead(iter->second);
	    iter->second->value = value;
	}
	else { // 不存在
	    if (_map.size()==_max) { // 若达到上限则删除链表末尾元素
		DListNode* node = removeTail();
		_map.erase(node->key);
		delete node;
	    }
	    _map[key] = new DListNode(key, value);
	    addToHead(_map[key]);
	}
    }
private:
    void addToHead(DListNode* node) {
	node->pre = _head;
	node->next = _head->next;
	_head->next = node;
	node->next->pre = node;
    }

    void remove(DListNode* node) {
	node->pre->next = node->next;
	node->next->pre = node->pre;
    }
    
    void moveToHead(DListNode* node) {
	remove(node);
	addToHead(node);
    }

    DListNode* removeTail() {
	DListNode* node = _tail->pre;
	remove(node);
	return node;
    }
    
    int _max;
    DListNode* _head;
    DListNode* _tail;
    unordered_map<int,DListNode*> _map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
