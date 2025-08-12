#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

//  Node Class Declaration
template <typename V>
class Node
{
public:
    V val;
    Node<V> *next;

    Node(V value); // Constructor declaration
};

//  Linked List Class Declaration
template <typename V>
class link
{
private:
    Node<V> *head;
    int size;

public:
    link();                                   // Constructor
    link(const link<V> &other);               // Copy Constructor
    link<V> &operator=(const link<V> &other); // Assignment Operator Overload
    V &operator[](int index);                 // Script Operator Overload
    link<V> &operator++();                    // Pre-Increment
    link<V> &operator--();                    // Pre-Decrement
    link<V> operator++(int);                  // Script Increment
    link<V> operator--(int);                  // Script Decrement
    ~link();                                  // Destructor

    void ins_beg(V value);            // Insert at beginning
    void ins_mid(V value, int place); // Insert at given index
    void ins_end(V value);            // Insert at end

    void del_beg();        // Delete from beginning
    void del_mid(V value); // Delete by value
    void del_end();        // Delete from end

    void dis();      // Display list
    int getsize();   // Get size
    V get_beg_val(); // Get Beg_Val
};

#include "LL_Source.cpp"
#endif // HEADER_H
