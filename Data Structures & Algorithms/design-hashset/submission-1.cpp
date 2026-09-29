#include <cstring>
class MyHashSet {
private:
    unsigned int set[31251];

    unsigned int getMask(int key) {
        return 1u << (key % 32);
    }

public:
    MyHashSet() {
        memset(set, 0, sizeof(set));
    }

    void add(int key) {
        set[key / 32] |= getMask(key);
    }

    void remove(int key) {
        if (contains(key)) {
            set[key / 32] &= ~getMask(key);
        }
    }

    bool contains(int key) {
        return (set[key / 32] & getMask(key)) != 0;
    }
};