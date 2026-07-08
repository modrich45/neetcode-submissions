class ListNode {
public:
    int key, val;
    ListNode *prev, *next;

    ListNode(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, ListNode*> mp;
    ListNode *head, *tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(ListNode* node) {
        ListNode* p = node->prev;
        ListNode* n = node->next;

        p->next = n;
        n->prev = p;
    }
    void insertFront(ListNode* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        ListNode* node = mp[key];

        removeNode(node);
        insertFront(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.count(key)) {
            ListNode* node = mp[key];
            node->val = value;

            removeNode(node);
            insertFront(node);
            return;
        }
        if (mp.size() == capacity) {
            ListNode* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        ListNode* node = new ListNode(key, value);
        insertFront(node);
        mp[key] = node;
    }
};