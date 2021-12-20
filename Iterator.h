#pragma once
#include<iostream>
using namespace std;

template<typename Node, typename T>
class Iterator
{
private:
    Node* m_ptr;
public:
    Iterator() : m_ptr(NULL) {}
    Iterator(Node* _ptr) : m_ptr(_ptr) {}
public:
    Node* get_ptr() { return m_ptr; }

    //префиксная форма
    Iterator& operator++() {
        if (m_ptr != NULL)
            m_ptr = m_ptr->next;
        return *this;
    }

    //постфиксная форма
    Iterator operator++(int) {
        Iterator it(*this);
        ++(*this);
        return it;
    }

    //префиксная форма
    Iterator& operator--() {
        if (m_ptr != NULL)
            m_ptr = m_ptr->prev;
        return *this;
    }

    //постфиксная форма
    Iterator operator--(int) {
        Iterator it(*this);
        --(*this);
        return it;
    }

    T& operator*() {
        return m_ptr->data;
    }

    bool operator==(const Node* ptr) const {
        return (m_ptr == ptr);
    }

    bool operator==(const Iterator& it) const {
        return (m_ptr == it.m_ptr);
    }

    bool operator!=(const Node* ptr) const {
        return (m_ptr != ptr);
    }

    bool operator!=(const Iterator& it) const {
        return (m_ptr != it.m_ptr);
    }
};
