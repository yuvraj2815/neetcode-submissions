#include <unordered_map>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int frequency;
        Node* previous;
        Node* next;

        Node(int key, int value, int frequency = 1)
            : key(key), value(value), frequency(frequency),
              previous(nullptr), next(nullptr) {}
    };

    struct FrequencyList {
        Node* head;
        Node* tail;
        int size;

        FrequencyList() : size(0) {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->previous = head;
        }

        void addToFront(Node* node) {
            node->next = head->next;
            node->previous = head;
            head->next->previous = node;
            head->next = node;
            size++;
        }

        void remove(Node* node) {
            node->previous->next = node->next;
            node->next->previous = node->previous;
            size--;
        }

        Node* removeLeastRecent() {
            if (size == 0) return nullptr;
            Node* node = tail->previous;
            remove(node);
            return node;
        }
    };

    int capacity;
    int minFrequency;
    unordered_map<int, Node*> nodes;
    unordered_map<int, FrequencyList*> lists;

    void increaseFrequency(Node* node) {
        int oldFrequency = node->frequency;
        FrequencyList* oldList = lists[oldFrequency];
        oldList->remove(node);

        if (oldFrequency == minFrequency && oldList->size == 0) {
            minFrequency++;
        }

        node->frequency++;
        if (!lists.count(node->frequency)) {
            lists[node->frequency] = new FrequencyList();
        }
        lists[node->frequency]->addToFront(node);
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFrequency(0) {}

    int get(int key) {
        if (!nodes.count(key)) return -1;

        Node* node = nodes[key];
        int result = node->value;
        increaseFrequency(node);
        return result;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (nodes.count(key)) {
            Node* node = nodes[key];
            node->value = value;
            increaseFrequency(node);
            return;
        }

        if (static_cast<int>(nodes.size()) == capacity) {
            Node* removed = lists[minFrequency]->removeLeastRecent();
            nodes.erase(removed->key);
            delete removed;
        }

        Node* node = new Node(key, value);
        nodes[key] = node;
        if (!lists.count(1)) {
            lists[1] = new FrequencyList();
        }
        lists[1]->addToFront(node);
        minFrequency = 1;
    }
};