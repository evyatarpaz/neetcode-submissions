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
        if(!node) return nullptr;

        std::unordered_map<Node*,Node*> clone_map;
        std::queue<Node*> q;

        clone_map[node] = new Node(node->val);
        q.emplace(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(auto neig : curr->neighbors){
                if(clone_map.find(neig) == clone_map.end()){
                    clone_map[neig] = new Node(neig->val);
                    q.emplace(neig);
                }
                clone_map[curr]->neighbors.emplace_back(clone_map[neig]);
            }
        }
        return clone_map[node];
    }
};
