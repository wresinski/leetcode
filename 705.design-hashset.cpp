class MyHashSet {
public:
    /** Initialize your data structure here. */

    struct Node
    {
        int val;
        Node* next;
        Node(int key):val(key),next(nullptr){}
    };

    MyHashSet() {

    }
    
    void add(int key) {
        Node* current = list[key%769];
        if(!current)
        {
            list[key%769] = new Node(key);
            return;
        }
        Node* pre;
        while(current)
        {
            if(current->val==key) return;
            pre = current;
            current = current->next;
        }
        pre->next = new Node(key);
    }
    
    void remove(int key) {
        Node* current = list[key%769];
        if(current)
        {
            if(current->val==key)
            {
                list[key%769] = current->next;
                delete current;
                return;
            }
            Node* pre = current;
            current = current->next;
            while(current)
            {
                if(current->val==key)
                {
                    pre->next = current->next;
                    delete current;
                    return;
                }
                pre = current;
                current = current->next;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        Node* current = list[key%769];
        while(current)
        {
            if(current->val==key) return true;
            current = current->next;
        }
        return false;
    }

private:
    Node* list[769] = { nullptr };
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
