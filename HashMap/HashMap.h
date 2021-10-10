#include "KeyHash.h"
#include "HashNode.h"

// Hash map class template
template <typename K, typename V, typename F = KeyHash<K>>
class HashMap {
public:
    HashMap() {
        // construct zero initialized hash table of size
        table = new HashNode<K, V> *[TABLE_SIZE]{nullptr};
    }

    ~HashMap() {
        // destroy all buckets one by one
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode<K, V> *entry = table[i];
            while (entry != nullptr) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }

            table[i] = nullptr;
        }
        // destroy the hash table
        delete [] table;
    }

    V& operator [](const K& key){
        auto hashValue = hashFunc(key);
        auto entry = table[hashValue];
        if(entry == nullptr) {
            table[hashValue] = new HashNode<K, V>(key);
            return table[hashValue]->getValue();
        }

        auto prev = entry;
        while(entry != nullptr && entry->getKey() != key){
            prev = entry;
            entry = entry->getNext();
        }

        if(entry == nullptr){
            entry = new HashNode<K, V>(key);
            prev->setNext(entry);
        }

        return entry->getValue();
    }

    void erase(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == nullptr) {
            // key not found
            return;
        }
        else {
            if (prev == nullptr) {
                // remove first bucket of the list
                table[hashValue] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            
            delete entry;
        }
    }

private:
    // hash table
    HashNode<K, V> **table;
    F hashFunc;
};