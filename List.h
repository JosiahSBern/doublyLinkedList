#include <iostream>
using namespace std;
/***************************************************************
 * Programmer: Josiah St Bernard
 * Date: February 11th, 2025
 * Purpose: Header for a doubly linked class
 * Input: None
 * Output: None
 **************************************************************/

#ifndef LIST_H
#define LIST_H

template <class T>
// Node structure with a next and prev pointer
struct node
{
    T info;
    node<T> *next;
    node<T> *prev;
};

template <class T>
class List
{
private:
    int length;
    
    node<T> *head;
    node<T> *tail;

public:
    // Constructor
    List();
    // Destrucor
    ~List();

    // Print List
    void printList();

    // Insert an item
    bool insertItem(const T);
    bool insertFront(const T);

    // Delete an item
    bool deleteItem(const T);

    // Getters
    int getLength();
    bool isEmpty() const;

    // Search for Item
    int searchItem(const T);

    // Operator =
    const List<T> &operator=(const List<T> &);

    // Copy Constructor
    List(const List<T> &);

    // Copy Method
    void copy(const List<T> &);

    // Destory Method
    void destroy();

    // Iterator class
    class Iterator
    {
    private:
        node<T> *current;

    public:
        Iterator();
        Iterator(node<T> *);

        // Increment
        Iterator operator++(int); // Post i++

        // Decrement
        Iterator operator--(int); // Post i--

        bool operator==(const Iterator &) const;
        bool operator!=(const Iterator &) const;

        T &operator*() const;
    };

    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();
};

#endif
