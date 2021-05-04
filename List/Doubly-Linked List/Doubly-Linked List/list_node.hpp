//
//  list_node.hpp
//  Singly-linked List
//
//  Created by Лабутин Антон Александрович on 15.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef list_node_hpp
#define list_node_hpp

#include <iostream>

template <typename T>
class ListNode {
    T key;
    ListNode *nextListNode = nullptr;
    ListNode *prevListNode = nullptr;

public:
    ListNode() {}
    ListNode(const T&);
    ListNode(const T&, ListNode<T> * const, ListNode<T> * const);
    ListNode(const ListNode<T> * const);

    const T&
    GetKey() const;

    T&
    GetKey();

    ListNode*
    GetNextNode() const;

    ListNode*
    GetPrevNode() const;

    void
    SetKey(const T&);

    void
    SetNextNode(ListNode<T>* const);

    void
    SetPrevNode(ListNode<T>* const);

    ~ListNode();
};

template <typename T>
std::ostream&
operator << (std::ostream& output, const ListNode<T>& node)
{
    output << node.GetKey();
    return output;
}

template<typename T>
ListNode<T>::ListNode(const T& new_key)
{
    key = new_key;
}

template<typename T>
ListNode<T>::ListNode(const T& newKey, ListNode<T> * const prevNode, ListNode<T> * const nextNode)
{
    key = newKey;
    prevListNode = prevNode;
    nextListNode = nextNode;
}

template <typename T>
ListNode<T>::ListNode(const ListNode<T> * const node)
{
    SetKey(node -> GetKey());
    SetNextNode(nullptr);
    SetPrevNode(nullptr);
}

template <typename T>
const T&
ListNode<T>::GetKey() const
{
    return key;
}

template <typename T>
T&
ListNode<T>::GetKey()
{
    return key;
}

template <typename T>
ListNode<T>*
ListNode<T>::GetNextNode() const
{
    return nextListNode;
}

template <typename T>
ListNode<T>*
ListNode<T>::GetPrevNode() const
{
    return prevListNode;
}

template <typename T>
void
ListNode<T>::SetKey(const T& new_key)
{
    key = new_key;
}

template<typename T>
void
ListNode<T>::SetNextNode(ListNode<T> * const newNextNode)
{
    nextListNode = newNextNode;
}

template <typename T>
void
ListNode<T>::SetPrevNode(ListNode<T> * const newPrevNode)
{
    prevListNode = newPrevNode;
}

template <typename T>
ListNode<T>::~ListNode()
{
    SetNextNode(nullptr);
    SetPrevNode(nullptr);
}

#endif /* list_node_hpp */
