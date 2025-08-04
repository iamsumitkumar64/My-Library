#ifndef HEADER_H
#define HEADER_H

// Include required standard libraries
#include <iostream>
using namespace std;

// ========== Node Class Declaration ==========
template <typename V>
class Node
{
public:
    V val;
    Node<V> *next;

    Node(V value); // Constructor declaration
};

// ========== Linked List Class Declaration ==========
template <typename V>
class LL
{
private:
    Node<V> *head;
    int size;

public:
    LL();  // Constructor
    ~LL(); // Destructor

    void ins_beg(V value);            // Insert at beginning
    void ins_mid(V value, int place); // Insert at given index
    void ins_end(V value);            // Insert at end

    void del_beg();        // Delete from beginning
    void del_mid(V value); // Delete by value
    void del_end();        // Delete from end

    void dis();    // Display list
    int getsize(); // Get size
};

#include "LL_Source.cpp"
#endif // HEADER_H
