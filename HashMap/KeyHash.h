#define TABLE_SIZE 10000

// Default hash function class
template <typename K>
struct KeyHash {
    unsigned long operator()(const K& key) const
    {
        return key % TABLE_SIZE;
    }
};