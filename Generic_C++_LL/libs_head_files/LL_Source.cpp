#include "LL_Head.h"
#include <iostream>
using namespace std;

// ============ Node Constructor =============
template <typename V>
Node<V>::Node(V value)
{
    this->val = value;
    next = nullptr;
}

// ============ LL Constructor =============
template <typename V>
LL<V>::LL()
{
    head = nullptr;
    size = 0;
}

// ============ Insert at Beginning =========
template <typename V>
void LL<V>::ins_beg(V value)
{
    Node<V> *newNode = new Node<V>(value);
    size++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// ============ Insert at Middle ============
template <typename V>
void LL<V>::ins_mid(V value, int place)
{
    if (place > size || place < 0)
    {
        cout << place << "th place is wrong as LL has " << size << " nodes";
        return;
    }
    if (place == 0)
    {
        ins_beg(value);
        return;
    }
    Node<V> *newNode = new Node<V>(value);
    Node<V> *temp = head;
    for (int i = 0; i < place - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

// ============ Insert at End ===============
template <typename V>
void LL<V>::ins_end(V value)
{
    Node<V> *newNode = new Node<V>(value);
    size++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node<V> *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

// ============ Delete from Beginning ========
template <typename V>
void LL<V>::del_beg()
{
    if (head == nullptr)
    {
        cout << "No Linked List Present\n";
        return;
    }
    Node<V> *temp = head;
    head = head->next;
    delete temp;
    size--;
}

// ============ Delete by Value (Middle) =====
template <typename V>
void LL<V>::del_mid(V value)
{
    if (head == nullptr)
    {
        cout << "No Linked List Present\n";
        return;
    }
    if (head->val == value)
    {
        Node<V> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    Node<V> *ptr = head->next;
    Node<V> *prev = head;
    while (ptr != nullptr)
    {
        if (ptr->val == value)
        {
            prev->next = ptr->next;
            delete ptr;
            size--;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    cout << "Value not found in Linked List\n";
}

// ============ Delete from End ===============
template <typename V>
void LL<V>::del_end()
{
    if (head == nullptr)
    {
        cout << "No Linked List Present\n";
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        size = 0;
        return;
    }
    Node<V> *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    size--;
}

// ============ Display Linked List ============
template <typename V>
void LL<V>::dis()
{
    if (head == nullptr)
    {
        cout << "No Linked List Present\n";
        return;
    }
    Node<V> *ptr = head;
    cout << "Start :->";
    while (ptr)
    {
        cout << "[" << ptr->val << "," << ptr->next << "]->";
        ptr = ptr->next;
    }
    cout << "nullptr";
}

// ============ Get Size ========================
template <typename V>
int LL<V>::getsize()
{
    return this->size;
}

// ============ Destructor ======================
template <typename V>
LL<V>::~LL()
{
    while (head)
    {
        Node<V> *temp = head;
        head = head->next;
        delete temp;
    }
}

// ============ Template Instantiations =========
// Add this at the bottom for all types you use
template class LL<int>;
template class Node<int>;