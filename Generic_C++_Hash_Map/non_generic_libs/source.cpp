#include "header.h"
using namespace std;

Node::Node(string data, int key)
{
    this->key = key;
    this->data = data;
    this->next = nullptr;
}

LL::LL()
{
    head = nullptr;
}

bool LL::LinkedExists(int key)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->key == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void LL::Linkedinsert(string data, int key)
{
    if (LinkedExists(key))
    {
        cout << "\tKey Exists Already\n";
        return;
    }
    Node *newNode = new Node(data, key);
    newNode->next = head;
    head = newNode;
}

void LL::Linkedremove(string data, int key)
{
    if (!head)
    {
        cout << "\tNo List Exists Here !\n";
        return;
    }
    if (!LinkedExists(key))
    {
        cout << "\tKey Not Exists\n";
        return;
    }
    if (head->data == data && head->key == key)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "\tDeleted Successfully\n";
        return;
    }
    Node *prev = head;
    Node *temp = head->next;
    while (temp)
    {
        if (temp->data == data && temp->key == key)
        {
            prev->next = temp->next;
            delete temp;
            cout << "\tDeleted Successfully\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\tNot found\n";
}

void LL::Linkedsearch(string data, int key)
{
    if (!head)
    {
        cout << "\tNo List Exists Here !\n";
        return;
    }
    Node *temp = head;
    int index = 0;
    while (temp)
    {
        if (temp->key == key && temp->data == data)
        {
            cout << "\tPresent At Posttion :" << index << "\n";
            return;
        }
        temp = temp->next;
        index++;
    }
    cout << "\tNot found\n";
}

void LL::Linkeddisplay()
{
    if (!head)
    {
        cout << "\tnullptr\n";
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << "{" << temp->key << " : " << temp->data << "} -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

int LL::Linkedcount()
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void LL::Linkedclear()
{
    Node *temp = head;
    while (temp)
    {
        Node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = nullptr;
}

Node *LL::getHead()
{
    return head;
}

LL::~LL()
{
    Linkedclear();
    cout << "Linked List Destructor Called\n";
}

Hash_map::Hash_map(int size)
{
    if (size < 0)
    {
        cout << "\tInvalid Size. Must be non-negative.\n";
        return;
    }
    this->size = size;
    lists = new LL[size];
}

Hash_map::Hash_map(const Hash_map &other)
{
    lists = new LL[size];
    for (int i = 0; i < size; ++i)
    {
        lists[i] = other.lists[i];
    }
}
int Hash_map::hashfunction(int key)
{
    return key % size;
}

void Hash_map::Hashinsert(const string &value, int key, int capacity)
{
    float percentage = (static_cast<float>(Hashcount()) / size) * 100;
    if (percentage > capacity)
    {
        HashReSize();
    }
    cout << "Percantage =>" << percentage << "\n";
    int index = hashfunction(key);
    lists[index].Linkedinsert(value, key);
}

void Hash_map::Hashremove(const string &value, int key)
{
    int index = hashfunction(key);
    lists[index].Linkedremove(value, key);
}

void Hash_map::Hashsearch(const string &value, int key)
{
    int index = hashfunction(key);
    cout << "\tIndex :" << index << "\n";
    lists[index].Linkedsearch(value, key);
}

void Hash_map::Hashdisplay(int key)
{
    int index = hashfunction(key);
    cout << "\tindex " << index << " : =>";
    lists[index].Linkeddisplay();
}

void Hash_map::HashdisplayAll()
{
    for (int i = 0; i < size; ++i)
    {
        cout << "\t" << i << " : =>";
        lists[i].Linkeddisplay();
    }
}

int Hash_map::Hashcount()
{
    int total = 0;
    for (int i = 0; i < size; ++i)
    {
        total += lists[i].Linkedcount();
    }
    return total;
}

void Hash_map::HashReSize()
{
    int old_size = size;
    LL *old_lists = lists;
    size *= 2;
    lists = new LL[size];
    for (int i = 0; i < old_size; ++i)
    {
        Node *current = old_lists[i].getHead();
        while (current)
        {
            int new_index = hashfunction(current->key);
            lists[new_index].Linkedinsert(current->data, current->key);
            current = current->next;
        }
    }
    delete[] old_lists;
}

bool Hash_map::Hashempty()
{
    return Hashcount() == 0;
}

void Hash_map::Hashclear()
{
    for (int i = 0; i < size; ++i)
    {
        lists[i].Linkedclear();
    }
}

Hash_map::~Hash_map()
{
    Hashclear();
    delete[] lists;
    cout << "HashMap Destructor Called\n";
}