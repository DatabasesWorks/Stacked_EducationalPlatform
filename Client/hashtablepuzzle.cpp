#include "hashtablepuzzle.h"

template<class K, class V>
V HashTablePuzzle<K,V>::getValue(K key){
    return m[key];
}

template<class K, class V>
void HashTablePuzzle<K, V>::insert(K key, V val){
    m[key] = val;
}

template<class K, class V>
void HashTablePuzzle<K, V>::erase(K key){
    m.erase(key);

}
