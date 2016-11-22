#ifndef HASHTABLEPUZZLE_H
#define HASHTABLEPUZZLE_H

#include <map>

template<class K, class V>
class HashTablePuzzle
{
public:
    HashTablePuzzle();
    V getValue(K);
    void insert(K, V);
    void erase(K);

private:
    std::map<K, V> m;
};

#endif // HASHTABLEPUZZLE_H
