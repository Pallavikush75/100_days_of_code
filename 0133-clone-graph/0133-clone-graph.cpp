class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        if (visited.count(node)) return visited[node];

        Node* copy = new Node(node->val);
        visited[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};