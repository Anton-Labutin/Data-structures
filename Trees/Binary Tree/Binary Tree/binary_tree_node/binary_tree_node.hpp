    //
    //  binary_tree_node.hpp
    //  Binary Tree
    //
    //  Created by Лабутин Антон Александрович on 17.08.2020.
    //  Copyright © 2020 Labutin Anton. All rights reserved.
    //

#ifndef binary_tree_node_hpp
#define binary_tree_node_hpp

#include <iostream>

using std::vector;

template <typename T>
class BinaryTreeNode {
    T key;
    BinaryTreeNode<T> *lessNode = nullptr;
    BinaryTreeNode<T> *greatertNode = nullptr;
    BinaryTreeNode<T> *parentNode = nullptr;

public:
    BinaryTreeNode() {};

    BinaryTreeNode(const T& key_, BinaryTreeNode<T> * const parent_);

    BinaryTreeNode(BinaryTreeNode<T> * const node);

    bool
    IsLeaf() const;

    T&
    GetKey();

    const T&
    GetKey() const;

    BinaryTreeNode<T>*
    GetLessNode();

    const BinaryTreeNode<T>*
    GetLessNode() const;

    BinaryTreeNode<T>*
    GetGreaterNode();

    const BinaryTreeNode<T>*
    GetGreaterNode() const;

    BinaryTreeNode<T>*
    GetParentNode();

    const BinaryTreeNode<T>*
    GetParentNode() const;

    void
    SetKey(const T&);

    void
    SetLessNode(BinaryTreeNode<T> * const);

    void
    SetGreaterNode(BinaryTreeNode<T> * const);

    void
    SetParentNode(BinaryTreeNode<T> * const);

    ~BinaryTreeNode();
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T& key_, BinaryTreeNode<T> * const parent_)
{
    SetKey(key_);
    SetParentNode(parent_);
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode( BinaryTreeNode<T> * const node)
{
    SetKey(node -> GetKey());

    SetLessNode(node -> GetLessNode());
    SetGreaterNode(node -> GetGreaterNode());
    SetParentNode(node -> GetParentNode());
}

template <typename T>
bool
BinaryTreeNode<T>::IsLeaf() const
{
    return ! (GetLessNode() || GetGreaterNode());
}

template <typename T>
T&
BinaryTreeNode<T>::GetKey()
{
    return key;
}

template <typename T>
const T&
BinaryTreeNode<T>::GetKey() const
{
    return key;
}

template <typename T>
BinaryTreeNode<T>*
BinaryTreeNode<T>::GetLessNode()
{
    return lessNode;
}

template <typename T>
const BinaryTreeNode<T>*
BinaryTreeNode<T>::GetLessNode() const
{
    return lessNode;
}

template <typename T>
BinaryTreeNode<T>*
BinaryTreeNode<T>::GetParentNode()
{
    return parentNode;
}

template <typename T>
const BinaryTreeNode<T>*
BinaryTreeNode<T>::GetParentNode() const
{
    return parentNode;
}

template <typename T>
BinaryTreeNode<T>*
BinaryTreeNode<T>::GetGreaterNode()
{
    return greatertNode;
}

template <typename T>
const BinaryTreeNode<T>*
BinaryTreeNode<T>::GetGreaterNode() const
{
    return greatertNode;
}

template <typename T>
void
BinaryTreeNode<T>::SetKey(const T& newKey)
{
    GetKey() = newKey;
}

template <typename T>
void
BinaryTreeNode<T>::SetLessNode( BinaryTreeNode<T> * const newNode)
{
    lessNode = newNode;
}

template <typename T>
void
BinaryTreeNode<T>::SetGreaterNode( BinaryTreeNode<T> * const newNode)
{
    greatertNode = newNode;
}

template <typename T>
void
BinaryTreeNode<T>::SetParentNode( BinaryTreeNode<T> * const parent)
{
    parentNode = parent;
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
    SetLessNode(nullptr);
    SetGreaterNode(nullptr);
    SetParentNode(nullptr);
}


#endif /* binary_tree_node_hpp */
