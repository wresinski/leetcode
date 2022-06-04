/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Solutio[MaÂ[M`Â[MaÂ[MaÂn1
        /*unordered_map<Node*,Node*> map;
        return getNode(head,map);*/

        //Solution2
       /* unordered_map<Node*,Node*> map;
        Node* dummy = new Node(0);
        Node* temp = dummy;
        while(head)
        {
            temp->next = map[head];
            if(!temp->next) 
            {
                temp->next = new Node(head->val);
                map[head] = temp->next;
            }
            if(head->random) 
            {
                temp->next->random = map[head->random];
                if(!temp->next->random) 
                {
                    temp->next->random = new Node(head->random->val);
                    map[head->random] = temp->next->random;
                }
            }
            head = head->next;
            temp = temp->next;
        }
        return dummy->next;*/

        //Solution3
        Node* temp = head;
        while(temp)
        {
            Node* next = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = next;
            temp = next;
        }
        temp = head;
        while(temp)
        {
            if(temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node* dummy = new Node(0);
        Node* temp2 = dummy;
        while(temp)
        {
            temp2->next = temp->next;
            temp2 = temp2->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    /*Node* getNode(Node* node,unordered_map<Node*,Node*> &map)
    {
        if(!node) return node;
        Node* res = map[node];
        if(!res)
        {
            res = new Node(node->val);
            map[node] = res;
            res->next = getNode(node->next,map);
            res->random = getNode(node->random,map);
        }
        return res;
    }*/
};
