#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

template <typename V, typename K>
class Node
{
private:
    V data;
    K key;
    Node<V, K> *next;

    Node(V data, K key);

    template <typename, typename>
    friend class LL;

    template <typename, typename>
    friend class Hash_map;
};

template <typename V, typename K>
class LL
{
private:
    Node<V, K> *head;

public:
    LL();
    ~LL();

    bool LinkedExists(K key);
    void Linkedinsert(V data, K key);
    void Linkedremove(V data, K key);
    void Linkedsearch(V data, K key);
    void Linkeddisplay();
    int Linkedcount();
    void Linkedclear();
    Node<V, K> *getHead();
    Node<V, K> *getPreviousNode(K key);
    bool setNode(K key, V newValue);
};

template <typename V, typename K>
class Hash_map
{
private:
    LL<V, K> *lists;
    int size;

    int hashfunction(K key);
    void HashReSize();

public:
    Hash_map(int size);
    Hash_map(const Hash_map &other);
    ~Hash_map();

    void Hashinsert(const V &value, K key, int capacity);
    void Hashremove(const V &value, K key);
    void Hashsearch(const V &value, K key);
    void Hashdisplay(K key);
    void HashdisplayAll();
    int Hashcount();
    bool Hashempty();
    void Hashclear();
};

#include "source.cpp"
#endif // HEADER_H