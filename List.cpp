#include <iostream>
#include "List.h"
/***************************************************************
 * Programmer: Josiah St Bernard
 * Date: February 11th, 2025
 * Purpose: Implementation of Doubly Linekd List Header
 * Input: None
 * Output: None
 **************************************************************/

using namespace std;

template <class T>
List<T>::List()
{
    length = 0;
    head = NULL; // head
    tail = NULL; // tail
}

// Destructor
template <class T>
List<T>::~List()
{
    destroy();
}

template <class T>
bool List<T>::insertFront(T item)
{
    node<T> *q = new node<T>;
    q->info = item;
    q->next = NULL;
    q->prev = NULL;

    // If empty
    if (head == NULL)
    {
        head = q;
        tail = q;
    }
    else
    {
        q->next = head;
        head->prev = q;
        head = q;
    }

    length++;
    return true;
}

// Insert Item (at the back)
template <class T>
bool List<T>::insertItem(T item)
{
    length++;
    node<T> *q = new node<T>;
    q->info = item;
    q->next = NULL;
    q->prev = NULL;

    // If head null
    if (head == NULL)
    {
        head = q;
        tail = q;
    }

    else
    {
        tail->next = q;
        q->prev = tail;
        tail = q;
    }
    return true;
}

template <class T>
void List<T>::printList()
{
    node<T> *curr = head;
    while (curr != NULL)
    {
        cout << curr->info << " ";
        curr = curr->next;
    }
}

template <class T>
bool List<T>::isEmpty() const
{
    return length == 0;
}

template <class T>
int List<T>::searchItem(const T item)
{
    int position = 1;
    node<T> *current = head;
    while (current != NULL)
    {
        if (current->info == item)
            return position;
        current = current->next;
        position++;
    }
    return -1;
}

template <class T>
bool List<T>::deleteItem(T item)
{
    node<T> *current = head;

    while (current && current->info != item)
    {
        current = current->next;
    }

    // If not found
    if (current == NULL)
        return false;

    // If it's the head
    if (current == head)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
    }
    // If it's the tail
    else if (current == tail)
    {
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
    }
    // Other nodes
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    length--;
    return true;
}

template <class T>
int List<T>::getLength()
{
    return length;
}

template <class T>
List<T>::List(const List<T> &other)
{
    head = tail = NULL;
    length = 0;
    copy(other);
}

template <class T>
void List<T>::copy(const List<T> &other)
{
    node<T> *curr = other.head;
    while (curr != NULL)
    {
        insertItem(curr->info);
        curr = curr->next;
    }
}

template <class T>
const List<T> &List<T>::operator=(const List<T> &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template <class T>
void List<T>::destroy()
{
    node<T> *p = head;
    while (p != NULL)
    {
        node<T> *q = p->next;
        delete p;
        p = q;
    }
    head = tail = NULL;
    length = 0;
}

/*********** Iterator Implementation *************/
template <class T>
List<T>::Iterator::Iterator()
{
    current = NULL;
}

// Increment operator
template <class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    if (current != NULL)
        current = current->next;
    return temp;
}

// Decrement operator
template <class T>
typename List<T>::Iterator List<T>::Iterator::operator--(int)
{
    Iterator q = *this;
    if (current != NULL)
        current = current->prev;
    return q;
}

template <class T>
T &List<T>::Iterator::operator*() const
{
    return current->info; 
}

template <class T>
bool List<T>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

template <class T>
bool List<T>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}

// Traversals

// Front to Back
template <class T>
typename List<T>::Iterator List<T>::begin()
{
    return Iterator(head);
}

template <class T>
typename List<T>::Iterator List<T>::end()
{
    return Iterator(NULL);
}

// Back to Front
template <class T>
typename List<T>::Iterator List<T>::rbegin()
{
    return Iterator(tail);
}

template <class T>
typename List<T>::Iterator List<T>::rend()
{
    return Iterator(NULL);
}

// Iterator constructor with parameter
template <class T>
List<T>::Iterator::Iterator(node<T> *ptr)
{
    current = ptr;
}

// template class List<int>;