#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    string data;
    int key;
    Node *next;
    Node(string data, int key);
    friend class LL;
    friend class Hash_map;
};

class LL
{
private:
    Node *head;

public:
    LL();
    void Linkedinsert(string data, int key);
    void Linkedremove(string data, int key);
    void Linkedsearch(string data, int key);
    bool LinkedExists(int key);
    void Linkeddisplay();
    int Linkedcount();
    Node *getHead();
    void Linkedclear();
    ~LL();
};

class Hash_map
{
private:
    LL *lists;
    int size;
    int hashfunction(int key);

public:
    Hash_map(int size);
    Hash_map(const Hash_map &other);
    void Hashinsert(const string &value, int key, int capacity);
    void Hashremove(const string &value, int key);
    void Hashsearch(const string &value, int key);
    void Hashdisplay(int key);
    void HashdisplayAll();
    int Hashcount();
    bool Hashempty();
    void Hashclear();
    void HashReSize();
    ~Hash_map();
};

#include "source.cpp"
#endif // HEADER_H