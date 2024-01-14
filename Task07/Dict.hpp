// Creator: Jeremi Toroj
// Date: 26.12.2023

#ifndef DICT_HPP
#define DICT_HPP

#include <utility>
#include <iostream>
#include "LinkedList.hpp"
#include "hash_function.hpp"

// ####################################  DECLARATION  #####################################

template <class K, class V>
class Dict
{
    using Pair = std::pair<K, V>;

private:
    int c_size;
    int buckets_n;
    LinkedList<K, V> *buckets_list;

public:
    Dict(int buckets_num);
    ~Dict();

    void clear();
    bool find(const K &key);
    bool insert(const Pair &pair);
    bool erase(const K &key);

    V &operator[](const K &key);

    int size();
    bool empty();
    void buckets();
};

// #################################### IMPLEMENTATION ####################################

template <class K, class V>
inline Dict<K, V>::Dict(int buckets_num)
{
    c_size = 0;
    buckets_n = buckets_num;
    buckets_list = new LinkedList<K, V>[buckets_num];

}

template <class K, class V>
inline Dict<K, V>::~Dict()
{
    delete[] buckets_list;
}

template <class K, class V>
inline void Dict<K, V>::clear()
{
    for (int i = 0; i < buckets_n; ++i)
    {
        buckets_list[i].clear();
    }
    c_size = 0;
}

template <class K, class V>
inline bool Dict<K, V>::find(const K &key)
{
    if (empty())
    {
        return false;
    }
    int bucket = hash_function(key, buckets_n);
    return buckets_list[bucket].find_key(key);
}

template <class K, class V>
inline bool Dict<K, V>::insert(const Pair &pair)
{
    K k = pair.first;
    V v = pair.second;
    int bucket = hash_function(k, buckets_n);
    
    if (buckets_list[bucket].find_pair(pair))
    {
        return false;
    }

    buckets_list[bucket].push_front(pair);
    c_size++;
    return true;
}

template <class K, class V>
inline bool Dict<K, V>::erase(const K &key)
{
    if (empty())
    {
        return false;
    }
    int bucket = hash_function(key, buckets_n);
    if (buckets_list[bucket].remove(key))
    {
        c_size--;
        return true;
    }
    return false;
}

template <class K, class V>
inline V &Dict<K, V>::operator[](const K &key)
{
    int bucket = hash_function(key, buckets_n);
    if (buckets_list[bucket].find_key(key))
    {
        return buckets_list[bucket].get(key);
    }

    Pair pair(key, V());
    buckets_list[bucket].push_front(pair);
    c_size++;
    return buckets_list[bucket].get(key);
}

template <class K, class V>
inline int Dict<K, V>::size()
{
    return c_size;
}

template <class K, class V>
inline bool Dict<K, V>::empty()
{
    return c_size == 0;
}

template <class K, class V>
inline void Dict<K, V>::buckets()
{
    
    int shortes = buckets_list[0].size();
    int longest = buckets_list[0].size();

    for (int i = 0; i < buckets_n; ++i)
    {
        int size = buckets_list[i].size();
        if (size < shortes)
        {
            shortes = size;
        }
        if (size > longest)
        {
            longest = size;
        }
    }

    std::cout << "#" << " " <<
    c_size << " " <<
    buckets_n << " " <<
    shortes << " " <<
    longest << " " << 
    std::endl;
}

#endif
