//
//  list.hpp
//  Singly-linked List
//
//  Created by Лабутин Антон Александрович on 15.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <iostream>
#include <cstddef>
#include <stdexcept>

#include "list_node.hpp"

template <typename T>
class List {
    ListNode<T> *head = nullptr;
    ListNode<T> *tail = nullptr;
    size_t listLen = 0;

    ListNode<T>*
    GetNodeBefore(const ListNode<T> *const) throw(std::runtime_error);

    ListNode<T>*
    GetNodeBeforeTail() throw(std::runtime_error);

    bool
    InList(const ListNode<T> * const node) const throw(std::runtime_error);

    void
    SetHead(ListNode<T> * const newHead);

    void
    SetTail(ListNode<T> * const newTail);

    void
    IncreaseListLen();

    void
    DecreaseListLen() throw(std::runtime_error);

public:
    List() {}
    List(size_t, const T&) throw(std::runtime_error);

    List(const List<T>& list);

    List<T>&
    operator = (const List<T>&);

    void
    PushFront(const T& key);

    void
    PushBack(const T& key);

    T&
    TopFront() throw (std::runtime_error);

    const T&
    TopFront() const throw (std::runtime_error);

    T&
    TopBack() throw (std::runtime_error);

    const T&
    TopBack() const throw (std::runtime_error);

    void
    PopFront() throw(std::runtime_error);

    void
    PopBack() throw(std::runtime_error);

    ListNode<T>*
    GetKeyPos(const T&) throw(std::runtime_error);

    const ListNode<T>*
    GetKeyPos(const T&) const throw(std::runtime_error);

    bool
    Find(const T& key) const throw(std::runtime_error);

    void
    Erase(const T& key) throw(std::runtime_error);

    bool
    Empty() const;

    void
    AddBefore(ListNode<T> * const nodeBefore, const T& key) throw(std::runtime_error);

    void
    AddAfter(ListNode<T> * const nodeAfter, const T& key) throw(std::runtime_error);

    ListNode<T>*
    GetHead();

    const ListNode<T>*
    GetHead() const;

    ListNode<T>*
    GetTail();

    const ListNode<T>*
    GetTail() const;

    size_t
    GetLen() const;

    void
    ClearList();

    ~List();
};

template <typename T>
List<T>::List(size_t size, const T& init_value) throw (std::runtime_error)
{
    if (size) {
        for (size_t i = 0; i < size; ++i) {
            PushBack(init_value);
        }
    } else {
        throw std::runtime_error("List(size, value) : size = 0");
    }
}

template <typename T>
List<T>::List(const List<T>& l)
{
    const ListNode<T> *currentNode = l.GetHead();
    while (currentNode) {
        PushBack(currentNode -> GetKey());
        currentNode = currentNode -> GetNextNode();
    }
}

template <typename T>
List<T>&
List<T>::operator = (const List<T>& l)
{
    const ListNode<T> *node = l.GetHead();

    ClearList();

    while (node) {
        PushBack(node -> GetKey());
        node = node -> GetNextNode();
    }

    return *this;
}

template <typename T>
std::ostream&
operator << (std::ostream& output, const List<T> &list)
{
    const ListNode<T> *currentNode = list.GetHead();
    size_t listLen = list.GetLen();

    bool isFirst = true;
    for (size_t i = 0; i < listLen; ++i) {
        if (! isFirst) {
            output << " ";
        }
        output << *currentNode;
        currentNode = currentNode -> GetNextNode();
        isFirst = false;
    }
    output << std::endl;

    return output;
}

template <typename T>
ListNode<T>*
List<T>::GetNodeBefore(const ListNode<T> * const node) throw(std::runtime_error)
{
    if (node) {
        if (InList(node)) {
            ListNode<T> *currentNode = GetHead();

            if (currentNode == node) {
                return nullptr;
            }

            while (currentNode && currentNode -> GetNextNode() != node) {
                currentNode = currentNode -> GetNextNode();
            }

            return currentNode;
        } else {
            throw std::runtime_error("GetNodeBefore : node is not in list");
        }
    } else {
        throw std::runtime_error("GetNodeBefore : node is nullptr");
    }
}

template <typename T>
ListNode<T>*
List<T>::GetNodeBeforeTail() throw(std::runtime_error)
{
    if (GetLen()) {
        return GetNodeBefore(GetTail());
    } else {
        throw std::runtime_error("GetNodeBeforeTail : list is empty");
    }
}

template <typename T>
ListNode<T>*
List<T>::GetKeyPos(const T& key) throw(std::runtime_error)
{
    ListNode<T> *currentNode = GetHead();
    if (currentNode) {
        while (currentNode && currentNode -> GetKey() != key) {
            currentNode = currentNode -> GetNextNode();
        }

        return currentNode;
    } else {
        throw std::runtime_error("GetKeyPos : list is empty");
    }
}

template <typename T>
const ListNode<T>*
List<T>::GetKeyPos(const T& key) const throw(std::runtime_error)
{
    const ListNode<T> *currentNode = GetHead();
    if (currentNode) {
        while (currentNode && currentNode -> GetKey() != key) {
            currentNode = currentNode -> GetNextNode();
        }

        return currentNode;
    } else {
        throw std::runtime_error("GetKeyPos : list is empty");
    }
}

template <typename T>
bool
List<T>::InList(const ListNode<T> *node) const throw (std::runtime_error)
{
    if (node == nullptr) {
        throw std::runtime_error("InList : node is nullptr");
    }

    ListNode<T> *currentNode = GetHead();
    while (currentNode && currentNode != node) {
        currentNode = currentNode -> GetNextNode();
    }

    return currentNode != nullptr;
}

template <typename T>
ListNode<T>*
List<T>::GetHead()
{
    return head;
}

template <typename T>
const ListNode<T>*
List<T>::GetHead() const
{
    return head;
}

template <typename T>
ListNode<T>*
List<T>::GetTail()
{
    return tail;
}

template <typename T>
const ListNode<T>*
List<T>::GetTail() const
{
    return tail;
}

template <typename T>
void
List<T>::SetHead(ListNode<T> * const newHead)
{
    head  = newHead;
}

template <typename T>
void
List<T>::SetTail(ListNode<T> * const newTail)
{
    tail = newTail;
}

template <typename T>
void
List<T>::IncreaseListLen()
{
    ++listLen;
}

template <typename T>
void
List<T>::DecreaseListLen() throw(std::runtime_error)
{
    if (listLen) {
        --listLen;
    } else {
        throw std::runtime_error("DecreaseListLen : list is empty");
    }
}

template <typename T>
size_t
List<T>::GetLen() const
{
    return listLen;
}

template <typename T>
void
List<T>::PushFront(const T& key)
{
    ListNode<T> * newNode = new ListNode<T>(key, GetHead());
    SetHead(newNode);
    IncreaseListLen();

    if (GetTail() == nullptr) {
        SetTail(newNode);
    }
}

template <typename T>
void
List<T>::PushBack(const T& key)
{
    ListNode<T> * newNode = new ListNode<T>(key);
    ListNode<T> * tail = GetTail();

    if (tail) {
        tail -> SetNextNode(newNode);
        SetTail(newNode);
    } else {
        SetHead(newNode);
        SetTail(newNode);
    }

    IncreaseListLen();
}

template <typename T>
T&
List<T>::TopFront() throw (std::runtime_error)
{
    if (GetHead()) {
        return GetHead() -> GetKey();
    } else {
        throw std::runtime_error("TopFront: list is empty");
    }
}

template <typename T>
const T&
List<T>::TopFront() const throw (std::runtime_error)
{
    if (GetHead()) {
        return GetHead() -> GetKey();
    } else {
        throw std::runtime_error("TopFront: list is empty");
    }
}

template <typename T>
T&
List<T>::TopBack() throw (std::runtime_error)
{
    if (GetTail()) {
        return GetTail() -> GetKey();
    } else {
        throw std::runtime_error("TopBack: list is empty");
    }
}

template <typename T>
const T&
List<T>::TopBack() const throw (std::runtime_error)
{
    if (GetTail()) {
        return GetTail() -> GetKey();
    } else {
        throw std::runtime_error("TopBack: list is empty");
    }
}

template <typename T>
void
List<T>::PopFront() throw (std::runtime_error)
{
    ListNode<T> *deleted = GetHead();

    if (deleted) {
        SetHead(deleted -> GetNextNode());
        DecreaseListLen();

        if (GetHead() == nullptr) {
            SetTail(nullptr);
        }

        delete deleted;
    } else {
        throw std::runtime_error("PopFront : list is empty");
    }
}

template <typename T>
void
List<T>::PopBack() throw(std::runtime_error)
{
    size_t len = GetLen();

    if (len) {
        if (len > 1) {
            ListNode<T> *nodeBeforeTail = GetNodeBeforeTail();
            delete GetTail();
            nodeBeforeTail -> SetNextNode(nullptr);
            SetTail(nodeBeforeTail);
        } else {
            delete GetHead();
            SetHead(nullptr);
            SetTail(nullptr);
        }

        DecreaseListLen();
    } else {
        throw std::runtime_error("PopBack : list is empty");
    }
}

template <typename T>
bool
List<T>::Find(const T& key) const throw(std::runtime_error)
{
    if (GetLen()) {
        const ListNode<T> *keyNode = GetKeyPos(key);

        return keyNode != nullptr;
    } else {
        throw std::runtime_error("Find : list is empty");
    }
}

template <typename T>
void
List<T>::Erase(const T& key) throw(std::runtime_error)
{
    if (GetLen()) {
        ListNode<T> *keyNode = GetKeyPos(key);

        if (keyNode) {
            ListNode<T> *nodeBeforeKey = GetNodeBefore(keyNode);

            if (nodeBeforeKey) {
                nodeBeforeKey -> SetNextNode(keyNode -> GetNextNode());
            } else {
                SetHead(keyNode -> GetNextNode());
            }

            if (keyNode == GetTail()) {
                SetTail(nodeBeforeKey);
            }

            delete keyNode;
            DecreaseListLen();
        } else {
            throw std::runtime_error("Erase : key is not in list");
        }
    } else {
        throw std::runtime_error("Erase : list is empty");
    }
}

template <typename T>
bool
List<T>::Empty() const
{
    return GetLen() == 0;
}

template <typename T>
void
List<T>::AddBefore(ListNode<T> * const nodeBefore, const T& key) throw(std::runtime_error)
{
    if (nodeBefore) {
        if (GetLen()) {
            if (InList(nodeBefore)) {
                ListNode<T> *newNode = new ListNode<T>(key, nodeBefore);
                ListNode<T> *nodeBeforeNew = GetNodeBefore(nodeBefore);
                if (nodeBeforeNew) {
                    nodeBeforeNew -> SetNextNode(newNode);
                } else {
                    SetHead(newNode);
                }

                IncreaseListLen();
            } else {
                throw std::runtime_error("AddBefore : nodeBefore is not in list");
            }
        } else {
            throw std::runtime_error("AddBefore : list is empty");
        }
    } else {
        throw std::runtime_error("AddBefore : nodeBefore is nullptr");
    }
}

template <typename T>
void
List<T>::AddAfter(ListNode<T> * const nodeAfter, const T& key) throw(std::runtime_error)
{
    if (nodeAfter) {
        if (GetLen()) {
            if (InList(nodeAfter)) {
                ListNode<T> * newNode = new ListNode<T>(key, nodeAfter -> GetNextNode());
                nodeAfter -> SetNextNode(newNode);
                IncreaseListLen();

                if (nodeAfter == GetTail()) {
                    SetTail(nodeAfter);
                }
            } else {
                throw std::runtime_error("AddAfter : nodeAfter is not in list");
            }
        } else {
            throw std::runtime_error("AddAfter : list is empty");
        }
    } else {
        throw std::runtime_error("AddAfter : nodeAfter is nullptr");
    }
}

template <typename T>
void
List<T>::ClearList()
{
    ListNode<T> *currentNode = GetHead();
    ListNode<T> *deleted = nullptr;

    while (currentNode) {
        deleted = currentNode;
        currentNode = currentNode -> GetNextNode();
        delete deleted;
        DecreaseListLen();
    }

    SetHead(nullptr);
    SetTail(nullptr);
}

template <typename T>
List<T>::~List()
{
    ClearList();
}


#endif /* list_hpp */
