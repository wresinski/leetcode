/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        //unordered_map<Node*,Node*> map;
        Node* map[101] = { nullptr };
        stack<Node*> st;
        map[node->val] = new Node(node->val);
        st.push(node);
        while(!st.empty())
        {
            Node* pOld = st.top();
            st.pop();
            Node* pNew = map[pOld->val];
            for(int i=0;i<pOld->neighbors.size();++i)
            {
                Node* tempOld = pOld->neighbors[i];
                Node* tempNew = map[tempOld->val];
                if(!tempNew)
                {
                    tempNew = new Node(tempOld->val);
                    map[tempOld->val] = tempNew;
                    st.push(tempOld);
                }
                pNew->neighbors.push_back(tempNew);
            }
        }
        return map[node->val];
    }
};
