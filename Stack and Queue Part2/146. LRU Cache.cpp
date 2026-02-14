// R
// https://leetcode.com/problems/lru-cache/description/
class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> um;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;
        head = nullptr;
        tail = nullptr;
    }

    // Add node at MRU position (tail)
    void addNode(Node* node) {
        if (!head) {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    // Remove node from list
    void removeNode(Node* node) {
        if (node == head && node == tail) {
            head = tail = nullptr;
        }
        else if (node == head) {
            head = head->next;
            head->prev = nullptr;
        }
        else if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    int get(int key) {
        if (um.find(key) == um.end())
            return -1;

        Node* node = um[key];
        removeNode(node);
        addNode(node);
        return node->value;
    }

    void put(int key, int value) {
        // Key already exists
        if (um.find(key) != um.end()) {
            Node* node = um[key];
            node->value = value;
            removeNode(node);
            addNode(node);
            return;
        }

        // Cache full → evict LRU
        if (um.size() == capacity) {
            um.erase(head->key);
            Node* temp = head;
            removeNode(head);
            delete temp;
        }

        // Insert new node
        Node* node = new Node(key, value);
        addNode(node);
        um[key] = node;
    }
};