#include "header.h"
// #include <functional>

// ===================== Node Constructor =====================
template <typename V, typename K>
Node<V, K>::Node(V data, K key)
{
    this->key = key;
    this->data = data;
    this->next = nullptr;
}

// ===================== LL Constructor =====================
template <typename V, typename K>
LL<V, K>::LL()
{
    head = nullptr;
}

// ===================== LL Destructor =====================
template <typename V, typename K>
LL<V, K>::~LL()
{
    Linkedclear();
    cout << "Linked List Destructor Called\n";
}

// ===================== LL Methods =====================
template <typename V, typename K>
bool LL<V, K>::LinkedExists(K key)
{
    Node<V, K> *temp = head;
    while (temp)
    {
        if (temp->key == key)
            return true;
        temp = temp->next;
    }
    return false;
}

template <typename V, typename K>
void LL<V, K>::Linkedinsert(V data, K key)
{
    if (LinkedExists(key))
    {
        bool isUpdate = setNode(key, data);
        if (isUpdate)
        {
            cout << "\tKey exists. Value updated.\n";
        }
        else
        {
            cout << "\tKey exists. Value not updated.\n";
        }
        return;
    }
    Node<V, K> *newNode = new Node<V, K>(data, key);
    newNode->next = head;
    head = newNode;
}
template <typename V, typename K>
void LL<V, K>::Linkedremove(V data, K key)
{
    if (!head)
    {
        cout << "\tNo List Exists Here!\n";
        return;
    }
    if (!LinkedExists(key))
    {
        cout << "\tKey Not Exists\n";
        return;
    }
    if (head->key == key && head->data == data)
    {
        Node<V, K> *toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "\tDeleted Successfully\n";
        return;
    }
    Node<V, K> *prev = getPreviousNode(key);
    if (prev && prev->next && prev->next->data == data)
    {
        Node<V, K> *toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        cout << "\tDeleted Successfully\n";
    }
    else
    {
        cout << "\tNot found\n";
    }
}

template <typename V, typename K>
void LL<V, K>::Linkedsearch(V data, K key)
{
    if (!head)
    {
        cout << "\tNo List Exists Here !\n";
        return;
    }
    Node<V, K> *temp = head;
    int index = 0;
    while (temp)
    {
        if (temp->key == key && temp->data == data)
        {
            cout << "\tPresent At Position :" << index << "\n";
            return;
        }
        temp = temp->next;
        index++;
    }
    cout << "\tNot found\n";
}

template <typename V, typename K>
void LL<V, K>::Linkeddisplay()
{
    if (!head)
    {
        cout << "\tnullptr\n";
        return;
    }
    Node<V, K> *temp = head;
    while (temp)
    {
        cout << "{" << temp->key << " : " << temp->data << "} -> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}

template <typename V, typename K>
int LL<V, K>::Linkedcount()
{
    int count = 0;
    Node<V, K> *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename V, typename K>
void LL<V, K>::Linkedclear()
{
    Node<V, K> *temp = head;
    while (temp)
    {
        Node<V, K> *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = nullptr;
}

template <typename V, typename K>
Node<V, K> *LL<V, K>::getHead()
{
    return head;
}
template <typename V, typename K>
Node<V, K> *LL<V, K>::getPreviousNode(K key)
{
    if (!head || head->key == key)
        return nullptr;

    Node<V, K> *prev = nullptr;
    Node<V, K> *current = head;

    while (current && current->key != key)
    {
        prev = current;
        current = current->next;
    }

    return current ? prev : nullptr;
}
template <typename V, typename K>
bool LL<V, K>::setNode(K key, V newValue)
{
    Node<V, K> *temp = head;
    while (temp)
    {
        if (temp->key == key)
        {
            temp->data = newValue;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// ===================== Hash_map Constructor =====================
template <typename V, typename K>
Hash_map<V, K>::Hash_map(int size)
{
    if (size < 0)
    {
        cout << "\tInvalid Size. Must be non-negative.\n";
        return;
    }
    this->size = size;
    lists = new LL<V, K>[size];
}

// ===================== Hash_map Copy Constructor =====================
template <typename V, typename K>
Hash_map<V, K>::Hash_map(const Hash_map &other)
{
    size = other.size;
    lists = new LL<V, K>[size];
    for (int i = 0; i < size; ++i)
    {
        Node<V, K> *node = other.lists[i].getHead();
        while (node)
        {
            lists[i].Linkedinsert(node->data, node->key);
            node = node->next;
        }
    }
}

// ===================== Hash_map Destructor =====================
template <typename V, typename K>
Hash_map<V, K>::~Hash_map()
{
    Hashclear();
    delete[] lists;
    cout << "HashMap Destructor Called\n";
}

// ===================== Hash_map Methods =====================
template <typename V, typename K>
int Hash_map<V, K>::hashfunction(K key)
{
    return static_cast<int>(std::hash<K>{}(key) % size);
}

template <typename V, typename K>
void Hash_map<V, K>::Hashinsert(const V &value, K key, int capacity)
{
    float percentage = (static_cast<float>(Hashcount()) / size) * 100;
    if (percentage > capacity)
    {
        HashReSize();
    }
    cout << "Percentage => " << percentage << "\n";
    int index = hashfunction(key);
    lists[index].Linkedinsert(value, key);
}

template <typename V, typename K>
void Hash_map<V, K>::Hashremove(const V &value, K key)
{
    int index = hashfunction(key);
    lists[index].Linkedremove(value, key);
}

template <typename V, typename K>
void Hash_map<V, K>::Hashsearch(const V &value, K key)
{
    int index = hashfunction(key);
    cout << "\tIndex :" << index << "\n";
    lists[index].Linkedsearch(value, key);
}

template <typename V, typename K>
void Hash_map<V, K>::Hashdisplay(K key)
{
    int index = hashfunction(key);
    cout << "\tindex " << index << " : =>";
    lists[index].Linkeddisplay();
}

template <typename V, typename K>
void Hash_map<V, K>::HashdisplayAll()
{
    for (int i = 0; i < size; ++i)
    {
        cout << "\t" << i << " : =>";
        lists[i].Linkeddisplay();
    }
}

template <typename V, typename K>
int Hash_map<V, K>::Hashcount()
{
    int total = 0;
    for (int i = 0; i < size; ++i)
    {
        total += lists[i].Linkedcount();
    }
    return total;
}

template <typename V, typename K>
bool Hash_map<V, K>::Hashempty()
{
    return Hashcount() == 0;
}

template <typename V, typename K>
void Hash_map<V, K>::Hashclear()
{
    for (int i = 0; i < size; ++i)
    {
        lists[i].Linkedclear();
    }
}

template <typename V, typename K>
void Hash_map<V, K>::HashReSize()
{
    int old_size = size;
    LL<V, K> *old_lists = lists;
    size *= 2;
    lists = new LL<V, K>[size];
    for (int i = 0; i < old_size; ++i)
    {
        Node<V, K> *current = old_lists[i].getHead();
        while (current)
        {
            int new_index = hashfunction(current->key);
            lists[new_index].Linkedinsert(current->data, current->key);
            current = current->next;
        }
    }
    delete[] old_lists;
}