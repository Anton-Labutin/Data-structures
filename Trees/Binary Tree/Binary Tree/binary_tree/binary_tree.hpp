//
//  binary_tree.hpp
//  Binary Tree
//
//  Created by Лабутин Антон Александрович on 17.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <algorithm>

using std::vector;

#include "../binary_tree_node/binary_tree_node.hpp"
#include "../queue/queue.hpp"

template <typename T>
class BinaryTree {
    BinaryTreeNode<T> *root = nullptr;
    size_t nodesCount = 0;

    void
    Insert(BinaryTreeNode<T> * const keyNode, BinaryTreeNode<T> *root) throw(std::runtime_error);

    BinaryTreeNode<T>*
    Search(const T& key, BinaryTreeNode<T> *root) throw(std::runtime_error);

    bool
    Search(const T& key, const BinaryTreeNode<T> *root) const throw(std::runtime_error);

    BinaryTreeNode<T>*
    Maximum(BinaryTreeNode<T> *root) throw (std::runtime_error);

    const T&
    Maximum(const BinaryTreeNode<T> *root) const throw(std::runtime_error);

    BinaryTreeNode<T> *
    Minimum(BinaryTreeNode<T> *root) throw (std::runtime_error);

    const T&
    Minimum(const BinaryTreeNode<T> *root) const throw(std::runtime_error);

    void
    InOrderTraversal(const BinaryTreeNode<T> *root, vector<T>& output) const; // центрированный / симметричный / инфиксный обход

    void
    PreOrderTraversal(const BinaryTreeNode<T> *root, vector<T>& output) const; // префиксный / прямой обход

    void
    PostOrderTraversal(const BinaryTreeNode<T> *root, vector<T>& output) const; // постфиксный / обратный обход

    void
    LevelTraversal(const BinaryTreeNode<T> *root, vector<T>& output) const;

    void
    Transplant(BinaryTreeNode<T> *oldRoot, BinaryTreeNode<T> *newRoot) throw(std::runtime_error);

    size_t
    Height(const BinaryTreeNode<T> * const root) const;

    void
    SetRoot(BinaryTreeNode<T> * const root);

    /*
     const BinaryTreeNode<T> *
     GetRoot() const;

     BinaryTreeNode<T> *
     GetRoot();
     */

    void
    Clear(BinaryTreeNode<T> *root) throw(std::runtime_error);

public:
    BinaryTree() {}
    BinaryTree(const T& key_)
        : root(new BinaryTreeNode<T>(key_, nullptr)), nodesCount(1)
    {}
    BinaryTree(BinaryTreeNode<T> * const root_)
        : root(root_), nodesCount(1)
    {}

    const BinaryTreeNode<T> *
    GetRoot() const;

    BinaryTreeNode<T> *
    GetRoot();

    void
    Insert(const T& key);

    BinaryTreeNode<T>*
    Search(const T& key);

    bool
    Search(const T& key) const;

    BinaryTreeNode<T>*
    Maximum();

    const T&
    Maximum() const throw(std::runtime_error);

    BinaryTreeNode<T> *
    Minimum();

    const T&
    Minimum() const throw(std::runtime_error);

    BinaryTreeNode<T>*
    Successor(BinaryTreeNode<T> *node) throw(std::runtime_error);

    BinaryTreeNode<T>*
    Predecessor(BinaryTreeNode<T> *node) throw(std::runtime_error);

    const BinaryTreeNode<T>*
    Successor(const BinaryTreeNode<T> *node) const throw(std::runtime_error);

    const BinaryTreeNode<T>*
    Predecessor(const BinaryTreeNode<T> *node) const throw(std::runtime_error);

    void
    Delete(BinaryTreeNode<T> *node) throw(std::runtime_error);

    void
    InOrderTraversal(vector<T>& output) const; // центрированный / симметричный / инфиксный обход

    void
    PreOrderTraversal(vector<T>& output) const; // префиксный / прямой обход

    void
    PostOrderTraversal(vector<T>& output) const; // постфиксный / обратный обход

    void
    LevelTraversal(vector<T>& output) const;

    size_t
    NodesCount() const;

    void
    IncreaseNodesCount();

    void
    DecreaseNodesCount();

    size_t
    Height() const;

    void
    Clear();

    ~BinaryTree();
 };

template <typename T>
void
BinaryTree<T>::SetRoot(BinaryTreeNode<T> * const newRoot)
{
    root = newRoot;
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::GetRoot()
{
    return root;
}

template <typename T>
const BinaryTreeNode<T>*
BinaryTree<T>::GetRoot() const
{
    return root;
}

template <typename T>
size_t
BinaryTree<T>::NodesCount() const
{
    return nodesCount;
}

template <typename T>
size_t
BinaryTree<T>::Height(const BinaryTreeNode<T> * const node) const
{
    if (node) {
        return 1 + std::max(Height(node -> GetLessNode()), Height(node -> GetGreaterNode()));
    } else {
        return 0;
    }
}

template <typename T>
size_t
BinaryTree<T>::Height() const
{
    if (NodesCount()) {
        return Height(GetRoot());
    } else {
        return 0;
    }
}

template <typename T>
void
BinaryTree<T>::IncreaseNodesCount()
{
    ++nodesCount;
}

template <typename T>
void
BinaryTree<T>::DecreaseNodesCount()
{
    if (nodesCount) {
        --nodesCount;
    } else {
        throw std::runtime_error("DecreaseNodesCount : tree is empty");
    }
}

template <typename T>
void
BinaryTree<T>::InOrderTraversal(const BinaryTreeNode<T> *node, vector<T> &output) const
{
    if (node) {
        InOrderTraversal(node -> GetLessNode(), output);
        output.push_back(node -> GetKey());
        InOrderTraversal(node -> GetGreaterNode(), output);
    }
}

template <typename T>
void
BinaryTree<T>::InOrderTraversal(vector<T>& output) const
{
    if (GetRoot()) {
        InOrderTraversal(GetRoot(), output);
    }
}

template <typename T>
void
BinaryTree<T>::PreOrderTraversal(const BinaryTreeNode<T> *node, vector<T> &output) const
{
    if (node) {
        output.push_back(node -> GetKey());
        PreOrderTraversal(node -> GetLessNode(), output);
        PreOrderTraversal(node -> GetGreaterNode(), output);
    }
}

template <typename T>
void
BinaryTree<T>::PreOrderTraversal(vector<T>& output) const
{
    if (GetRoot()) {
        PreOrderTraversal(GetRoot(), output);
    }
}

template <typename T>
void
BinaryTree<T>::PostOrderTraversal(const BinaryTreeNode<T> *node, vector<T> &output) const
{
    if (node) {
        PostOrderTraversal(node -> GetLessNode(), output);
        PostOrderTraversal(node -> GetGreaterNode(), output);
        output.push_back(node -> GetKey());
    }
}

template <typename T>
void
BinaryTree<T>::PostOrderTraversal(vector<T>& output) const
{
    if (GetRoot()) {
        PostOrderTraversal(GetRoot(), output);
    }
}

template <typename T>
void
BinaryTree<T>::LevelTraversal(const BinaryTreeNode<T> *root, vector<T>& output) const
{
    if (root) {
        Queue<const BinaryTreeNode<T>*> treeLevel;
        treeLevel.Enqueue(root);
        const BinaryTreeNode<T> *currentNode = nullptr;

        while (! treeLevel.Empty()) {
            currentNode = treeLevel.Dequeue();
            output.push_back(currentNode -> GetKey());

            if (currentNode -> GetLessNode()) {
                treeLevel.Enqueue(currentNode -> GetLessNode());
            }

            if (currentNode -> GetGreaterNode()) {
                treeLevel.Enqueue(currentNode -> GetGreaterNode());
            }
        }
    }
}

template <typename T>
void
BinaryTree<T>::LevelTraversal(vector<T>& output) const
{
    if (NodesCount()) {
        LevelTraversal(GetRoot(), output);
    }
}

template <typename T>
void
BinaryTree<T>::Insert(BinaryTreeNode<T> * const keyNode,  BinaryTreeNode<T> *root) throw(std::runtime_error)
{
    if (keyNode) {
        if (root) {
            while (! root -> IsLeaf()) {
                if (keyNode -> GetKey() <= root -> GetKey()) {
                    if (root -> GetLessNode()) {
                        root = root -> GetLessNode();
                    } else {
                        break;
                    }
                } else {
                    if (root -> GetGreaterNode()) {
                        root = root -> GetGreaterNode();
                    } else {
                        break;
                    }
                }
            }

            if (keyNode -> GetKey() <= root -> GetKey()) {
                root -> SetLessNode(keyNode);
            } else {
                root -> SetGreaterNode(keyNode);
            }
            keyNode -> SetParentNode(root);
        } else {
            throw std::runtime_error("Insert(key, root) : root is nullptr");
        }
    } else {
        throw std::runtime_error("Insert(node, root) : node is nullptr");
    }
}

template <typename T>
void
BinaryTree<T>::Insert(const T& key)
{
    BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(key, nullptr);

    if (NodesCount()) {
        Insert(newNode, GetRoot());
    } else {
        SetRoot(newNode);
    }

    IncreaseNodesCount();
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Search(const T& key, BinaryTreeNode<T> *node) throw(std::runtime_error)
{
    if (node) {
        while (node && node -> GetKey() != key) {
            if (key <= node -> GetKey()) {
                node = node -> GetLessNode();
            } else {
                node = node -> GetGreaterNode();
            }
        }

        return node;
    } else {
        throw std::runtime_error("Search(key, node) : node is empty");
    }
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Search(const T& key)
{
    if (NodesCount()) {
        return Search(key, GetRoot());
    } else {
        return nullptr;
    }
}

template <typename T>
bool
BinaryTree<T>::Search(const T& key, const BinaryTreeNode<T> *node) const throw(std::runtime_error)
{
    if (node) {
        while (node && node -> GetKey() != key) {
            if (key <= node -> GetKey()) {
                node = node -> GetLessNode();
            } else {
                node = node -> GetGreaterNode();
            }
        }

        return node != nullptr;
    } else {
        throw std::runtime_error("Search(key, node) const : node is empty");
    }
}

template <typename T>
bool
BinaryTree<T>::Search(const T& key) const
{
    if (NodesCount()) {
        Seatch(key, GetRoot());
    } else {
        return false;
    }
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Minimum(BinaryTreeNode<T> *node) throw (std::runtime_error)
{
    if (node) {
        while (node && node -> GetLessNode()) {
            node = node -> GetLessNode();
        }

        return node;
    } else {
        throw std::runtime_error("Minimum(node) : node is nullptr");
    }
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Minimum()
{
    if (NodesCount()) {
        return Minimum(GetRoot());
    } else {
        return nullptr;
    }
}

template <typename T>
const T&
BinaryTree<T>::Minimum(const BinaryTreeNode<T> *node) const throw (std::runtime_error)
{
    if (node) {
        while (node && node -> GetLessNode()) {
            node = node -> GetLessNode();
        }

        return node -> GetKey();
    } else {
        throw std::runtime_error("Minimum(node) const : node is nullptr");
    }
}

template <typename T>
const T&
BinaryTree<T>::Minimum() const throw(std::runtime_error)
{
    if (NodesCount()) {
        return Minimum(GetRoot());
    } else {
        throw std::runtime_error("Minimum() const : tree is empty");
    }
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Maximum(BinaryTreeNode<T> *node) throw (std::runtime_error)
{
    if (node) {
        while (node && node -> GetGreaterNode()) {
            node = node -> GetGreaterNode();
        }

        return node;
    } else {
        throw std::runtime_error("Maximum(node) : node is nullptr");
    }
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Maximum()
{
    if (NodesCount()) {
        return Maximum(GetRoot());
    } else {
        return nullptr;
    }
}

template <typename T>
const T&
BinaryTree<T>::Maximum(const BinaryTreeNode<T> *node) const throw (std::runtime_error)
{
    if (node) {
        while (node && node -> GetGreaterNode()) {
            node = node -> GetGreaterNode();
        }

        return node -> GetKey();
    } else {
        throw std::runtime_error("Maximum(node) const : node is nullptr");
    }
}

template <typename T>
const T&
BinaryTree<T>::Maximum() const throw(std::runtime_error)
{
    if (NodesCount()) {
        Maximum(GetRoot());
    } else {
        throw std::runtime_error("Maximum() const : tree is empty");
    }
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Successor(BinaryTreeNode<T> *node) throw(std::runtime_error)
{
    if (node) {
        if (node -> GetGreaterNode()) {
            return Minimum(node -> GetGreaterNode());
        } else {
            BinaryTreeNode<T> *greaterNode = node -> GetParentNode();
            while (greaterNode && node == (greaterNode -> GetGreaterNode())) {
                node = greaterNode;
                greaterNode = greaterNode -> GetParentNode();
            }

            return greaterNode;
        }
    } else {
        throw std::runtime_error("Successor : node is nullptr");
    }
}

template <typename T>
BinaryTreeNode<T>*
BinaryTree<T>::Predecessor(BinaryTreeNode<T> *node) throw(std::runtime_error)
{
    if (node) {
        if (node -> GetLessNode()) {
            return Maximum(node -> GetLessNode());
        } else {
            BinaryTreeNode<T> *lessNode = node -> GetParentNode();
            while (lessNode && node == lessNode -> GetLessNode()) {
                node = lessNode;
                lessNode = lessNode -> GetParentNode();
            }

            return lessNode;
        }
    } else {
        throw std::runtime_error("Predecessor : node is nullptr");
    }
}

template <typename T>
const BinaryTreeNode<T>*
BinaryTree<T>::Successor(const BinaryTreeNode<T> *node) const throw(std::runtime_error)
{
    if (node) {
        if (node -> GetGreaterNode()) {
            return Minimum(node -> GetGreaterNode());
        } else {
            BinaryTreeNode<T> *greaterNode = node -> GetParentNode();
            while (greaterNode && node == greaterNode -> GetGreaterNode()) {
                node = greaterNode;
                greaterNode = greaterNode -> GetParentNode();
            }

            return greaterNode;
        }
    } else {
        throw std::runtime_error("Successor : node is nullptr");
    }
}

template <typename T>
const BinaryTreeNode<T>*
BinaryTree<T>::Predecessor(const BinaryTreeNode<T> *node) const throw(std::runtime_error)
{
    if (node) {
        if (node -> GetLessNode()) {
            return Maximum(node -> GetLessNode());
        } else {
            BinaryTreeNode<T> *lessNode = node -> GetParentNode();
            while (lessNode && node == lessNode -> GetLessNode()) {
                node = lessNode;
                lessNode = lessNode -> GetParentNode();
            }

            return lessNode;
        }
    } else {
        throw std::runtime_error("Predecessor : node is nullptr");
    }
}

template <typename T>
void
BinaryTree<T>::Transplant(BinaryTreeNode<T> *oldRoot, BinaryTreeNode<T> *newRoot) throw(std::runtime_error)
{
    if (oldRoot) {
        if (oldRoot -> GetParentNode() == nullptr) {
            SetRoot(newRoot);
        } else {
            if (oldRoot == oldRoot -> GetParentNode() -> GetLessNode()) {
                oldRoot -> GetParentNode() -> SetLessNode(newRoot);
            } else {
                oldRoot -> GetParentNode() -> SetGreaterNode(newRoot);
            }
        }

        if (newRoot != nullptr) {
            newRoot -> SetParentNode(oldRoot -> GetParentNode());
        }
    } else {
        throw std::runtime_error("Transplant(old, new) : old is nullptr");
    }
}

template <typename T>
void
BinaryTree<T>::Delete(BinaryTreeNode<T> *deletedNode) throw(std::runtime_error)
{
    if (deletedNode) {
        if (deletedNode -> GetLessNode() == nullptr) {
            Transplant(deletedNode, deletedNode -> GetGreaterNode());
        } else {
            if (deletedNode -> GetGreaterNode() == nullptr) {
                Transplant(deletedNode, deletedNode -> GetLessNode());
            } else {
                BinaryTreeNode<T> *successor = Minimum(deletedNode -> GetGreaterNode());

                if (deletedNode != successor -> GetParentNode()) {
                    Transplant(successor, successor -> GetGreaterNode());
                    successor -> SetGreaterNode(deletedNode -> GetGreaterNode());
                    successor -> GetGreaterNode() -> SetParentNode(successor);
                }

                Transplant(deletedNode, successor);
                successor -> SetLessNode(deletedNode -> GetLessNode());
                successor -> GetLessNode() -> SetParentNode(successor);
            }
        }

        delete deletedNode;
        DecreaseNodesCount();
    } else {
        throw std::runtime_error("Delete (node): deletedNode is nullptr");
    }
}

template <typename T>
void
BinaryTree<T>::Clear(BinaryTreeNode<T> *root) throw(std::runtime_error)
{
    if (root) {
        if (root -> GetLessNode()) {
            Clear(root -> GetLessNode());
        }
        if (root -> GetGreaterNode()) {
            Clear(root -> GetGreaterNode());
        }

        delete root;
        DecreaseNodesCount();
    } else {
        throw std::runtime_error("Clear(root) : root is nullptr");
    }
}

template <typename T>
void
BinaryTree<T>::Clear()
{
    if (NodesCount()) {
        Clear(GetRoot());
        SetRoot(nullptr);
    }
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    Clear();
}

#endif /* binary_tree_hpp */
