#pragma once
#include <string>
#include <iostream>

using namespace std;

template <typename K, typename V>
struct Node
{
    K key;
    V value;
    Node *next;

    Node(K k, V v) : key(k), value(v), next(nullptr) {}
};

template <typename K, typename V>
class Hashtable
{
private:
    Node<K, V> **bucket;
    int size;
    int capacity;
    int thresold = 75;

    int hash(int key)
    {
        return key % capacity;
    }

    int hash(char key)
    {
        return static_cast<unsigned char>(key) % capacity;
    }

    int hash(std::string key)
    {
        int hash = 0;
        for (char c : key)
        {
            hash = (hash * 31 + static_cast<unsigned char>(c)) % capacity;
        }
        return hash;
    }

    int hash(char *key)
    {
        int hash = 0;
        while (*key)
        {
            hash = (hash * 31 + static_cast<unsigned char>(*key++)) % capacity;
        }
        return hash;
    }

    Node<K, V> *findLastNode(Node<K, V> *head)
    {
        while (head->next != nullptr)
        {
            head = head->next;
        }
        return head;
    }

    void resize()
    {

        size_t oldCapacity = capacity;
        size_t newCapacity = oldCapacity * 2;
        Node<K, V> **oldBucket = bucket;
        capacity = newCapacity;
        bucket = new Node<K, V> *[newCapacity];
        for (size_t i = 0; i < newCapacity; i++)
        {
            bucket[i] = nullptr;
        }
        size = 0;
        for (size_t i = 0; i < oldCapacity; i++)
        {
            Node<K, V> *head = oldBucket[i];
            while (head)
            {
                insert(head->key, head->value);
                head = head->next;
            }
        }
        destroy(oldBucket, oldCapacity);
    }

    void destroy(Node<K, V> **bucket, int capacity)
    {
        Node<K, V> *temp;
        for (size_t i = 0; i < capacity; i++)
        {
            Node<K, V> *head = bucket[i];
            if (head == nullptr)
                continue;
            while (head)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }
        delete[] bucket;
    }

public:
    Hashtable()
    {
        bucket = new Node<K, V> *[10];
        size = 0;
        capacity = 10;
        for (size_t i = 0; i < capacity; i++)
        {
            bucket[i] = nullptr;
        }
    }

    ~Hashtable()
    {
        destroy(bucket, capacity);
    }

    void insert(K key, V value)
    {
        int index = hash(key);
        int currThresold = (static_cast<float>(size) / capacity) * 100;
        if (currThresold > thresold)
        {
            resize();
        }
        size++;
        Node<K, V> *newNode = new Node<K, V>(key, value);
        if (bucket[index] == nullptr)
        {
            bucket[index] = newNode;
            return;
        }
        Node<K, V> *lastNode = findLastNode(bucket[index]);
        lastNode->next = newNode;
    }
    V get(K key)
    {
        int index = hash(key);
        Node<K, V> *head = bucket[index];

        while (head != nullptr)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }

        throw std::runtime_error("Key not found");
    }

    V remove(K key)
    {
        int index = hash(key);
        Node<K, V> *head = bucket[index];
        if (head == nullptr)
            throw std::runtime_error("Key not found");

        if (head->key == key)
        {
            Node<K, V> *temp = head;
            V returnValue = temp->value;
            bucket[index] = head->next;
            delete temp;
            return returnValue;
        }
        while (head->next != nullptr && head->next->key != key)
        {
            head = head->next;
        }

        if (head->next == nullptr)
            throw std::runtime_error("Key not found");
        Node<K, V> *temp = head->next;
        V returnValue = temp->value;
        head->next = head->next->next;
        delete temp;
        return returnValue;
    }

    void debug()
    {
        for (int i = 0; i < capacity; i++)
        {
            std::cout << "Bucket[" << i << "]: ";
            Node<K, V> *curr = bucket[i];
            while (curr != nullptr)
            {
                std::cout << "(" << curr->key << "," << curr->value << ") -> ";
                curr = curr->next;
            }
            std::cout << "nullptr" << std::endl;
        }
    }
};