/* Google
Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

set(key, value): sets key to value. If there are already n items in the cache
and we are adding a new item, then it should also remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
*/



class Node {
public:

    int val;
    int key;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    void addNode(Node* cur) {
        cur->prev = tail->prev;
        cur->next = tail;

        tail->prev->next = cur;
        tail->prev = cur;
    }

    void moveToTail(Node* cur) {
        removeNode(cur);
        addNode(cur);
    }

    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        Node* temp = map[key];
        moveToTail(temp);
        return temp->val;
     }

    void put(int key, int value) {
        if(map.find(key) != map.end() ) {
            Node* temp = map[key];
            temp->val = value;
            moveToTail(temp);
            return;
        }

        if( map.size() >= size ) {
            Node* temp = head->next;
            removeNode(temp);
            map.erase(temp->key);
            delete temp;
        }

        Node* newNode = new Node();
        newNode->val = value;
        newNode->key = key;
        map[key] = newNode;

        addNode(newNode);
    }
private:
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int size;
};
