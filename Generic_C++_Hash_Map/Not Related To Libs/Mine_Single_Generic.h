#include <iostream>
using namespace std;

template <typename V, typename K>
class Node
{
private:
    V data;
    K key;
    Node<V, K> *next;

    Node(V data, K key)
    {
        this->key = key;
        this->data = data;
        this->next = nullptr;
    }

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
    LL() { head = nullptr; }

    bool LinkedExists(K key)
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

    void Linkedinsert(V data, K key)
    {
        if (LinkedExists(key))
        {
            cout << "\tKey Exists Already\n";
            return;
        }
        Node<V, K> *newNode = new Node<V, K>(data, key);
        newNode->next = head;
        head = newNode;
    }

    void Linkedremove(V data, K key)
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
            Node<V, K> *toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "\tDeleted Successfully\n";
            return;
        }
        Node<V, K> *prev = head;
        Node<V, K> *temp = head->next;
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

    void Linkedsearch(V data, K key)
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

    void Linkeddisplay()
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

    int Linkedcount()
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

    void Linkedclear()
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

    Node<V, K> *getHead() { return head; }

    ~LL()
    {
        Linkedclear();
        cout << "Linked List Destructor Called\n";
    }
};

template <typename V, typename K>
class Hash_map
{
private:
    LL<V, K> *lists;
    int size;

    int hashfunction(K key)
    {
        // return static_cast<int>(key) % size;
        return static_cast<int>(std::hash<K>{}(key) % size);
    }

public:
    Hash_map(int size)
    {
        if (size < 0)
        {
            cout << "\tInvalid Size. Must be non-negative.\n";
            return;
        }
        this->size = size;
        lists = new LL<V, K>[size];
    }

    Hash_map(const Hash_map &other)
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
    void Hashinsert(const V &value, K key, int capacity)
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

    void Hashremove(const V &value, K key)
    {
        int index = hashfunction(key);
        lists[index].Linkedremove(value, key);
    }

    void Hashsearch(const V &value, K key)
    {
        int index = hashfunction(key);
        cout << "\tIndex :" << index << "\n";
        lists[index].Linkedsearch(value, key);
    }

    void Hashdisplay(K key)
    {
        int index = hashfunction(key);
        cout << "\tindex " << index << " : =>";
        lists[index].Linkeddisplay();
    }

    void HashdisplayAll()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << "\t" << i << " : =>";
            lists[i].Linkeddisplay();
        }
    }

    int Hashcount()
    {
        int total = 0;
        for (int i = 0; i < size; ++i)
        {
            total += lists[i].Linkedcount();
        }
        return total;
    }

    bool Hashempty()
    {
        return Hashcount() == 0;
    }

    void Hashclear()
    {
        for (int i = 0; i < size; ++i)
        {
            lists[i].Linkedclear();
        }
    }

    void HashReSize()
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

    ~Hash_map()
    {
        Hashclear();
        delete[] lists;
        cout << "HashMap Destructor Called\n";
    }
};