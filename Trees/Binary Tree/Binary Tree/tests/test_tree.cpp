//
//  tests.cpp
//  Binary Tree
//
//  Created by Лабутин Антон Александрович on 17.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include "test_tree.hpp"
#include "../binary_tree/binary_tree.hpp"
#include "../test_template/test_runner.hpp"

#include <vector>

void
TestBinaryTreeConstructor()
{
    BinaryTree<int> bt1;
    AssertEqual(bt1.NodesCount(), 0, "bt1 is empty");
    AssertEqual(bt1.Height(), 0, "bt1 has height 1");

    BinaryTreeNode<double> *root = new BinaryTreeNode<double>(1.0, nullptr);
    BinaryTree<double> bt2(root);
    AssertEqual(bt2.NodesCount(), 1, "bt2 has only root");
    AssertEqual(bt2.GetRoot(), root, "bt2 has only root");
    AssertEqual(bt2.Height(), 1, "bt2 has height 1");

    BinaryTree<int> bt3(2);
    AssertEqual(bt3.NodesCount(), 1, "bt3 has only root");
    AssertEqual(bt3.Height(), 1, "bt3 has height 1");
}

void
TestBinaryTreeInsert()
{
    BinaryTree<int> bt1(10);
    bt1.Insert(11);

    AssertEqual(bt1.NodesCount(), 2, "bt1 has 2 nodes");
    AssertEqual(bt1.Height(), 2, "bt1 has height 2");
    Assert(bt1.Search(11) -> GetParentNode() == bt1.Search(10), "bt1: node 11 has parent 10");

    bt1.Insert(12);
    AssertEqual(bt1.NodesCount(), 3, "bt1 has 3 nodes");
    AssertEqual(bt1.Height(), 3, "bt1 has height 3");
    Assert(bt1.Search(11) -> GetParentNode() == bt1.Search(10), "bt1: node 11 has parent 10");
    Assert(bt1.Search(12) -> GetParentNode() == bt1.Search(11), "bt1: node 12 has parent 11");

    bt1.Insert(9);
    AssertEqual(bt1.NodesCount(), 4, "bt1 has 4 nodes");
    AssertEqual(bt1.Height(), 3, "bt1 has height 3");
    Assert(bt1.Search(9) -> GetParentNode() == bt1.Search(10), "bt1: node 9 has parent 10");

    bt1.Insert(5);
    AssertEqual(bt1.NodesCount(), 5, "bt1 has 5 nodes");
    AssertEqual(bt1.Height(), 3, "bt1 has height 3");
    Assert(bt1.Search(5) -> GetParentNode() == bt1.Search(9), "bt1: node 5 has parent 9");

    bt1.Insert(4);
    AssertEqual(bt1.NodesCount(), 6, "bt1 has 6 nodes");
    AssertEqual(bt1.Height(), 4, "bt1 has height 4");
    Assert(bt1.Search(4) -> GetParentNode() == bt1.Search(5), "bt1: node 4 has parent 5");
 }

void
TestBinaryTreeSearch()
{
    BinaryTree<int> bt1(10);
    Assert(bt1.Search(10) != nullptr, "bt1 has node 10");
    Assert(bt1.Search(11) == nullptr, "bt1 does not have node 11");

    bt1.Insert(11);
    Assert(bt1.Search(11) != nullptr, "bt1 has node 11");
}

void
TestBinaryTreeMaximum()
{
    BinaryTree<int> bt1(10);
    AssertEqual(bt1.Maximum() -> GetKey(), 10, "bt1 has maximum 10");

    bt1.Insert(11);
    AssertEqual(bt1.Maximum() -> GetKey(), 11, "bt1 has maximum 11");

    bt1.Insert(12);
    AssertEqual(bt1.Maximum() -> GetKey(), 12, "bt1 has maximum 12");

    bt1.Insert(9);
    AssertEqual(bt1.Maximum() -> GetKey(), 12, "bt1 has maximum 12");

    bt1.Insert(10);
    AssertEqual(bt1.Maximum() -> GetKey(), 12, "bt1 has maximum 12");

    bt1.Insert(5);
    AssertEqual(bt1.Maximum() -> GetKey(), 12, "bt1 has maximum 12");

    bt1.Insert(4);
    AssertEqual(bt1.Maximum() -> GetKey(), 12, "bt1 has maximum 12");
}

void
TestBinaryTreeMinimum()
{
    BinaryTree<int> bt1(10);
    AssertEqual(bt1.Minimum() -> GetKey(), 10, "bt1 has minimum 10");

    bt1.Insert(11);
    AssertEqual(bt1.Minimum() -> GetKey(), 10, "bt1 has minimum 10");

    bt1.Insert(12);
    AssertEqual(bt1.Minimum() -> GetKey(), 10, "bt1 has minimum 10");

    bt1.Insert(9);
    AssertEqual(bt1.Minimum() -> GetKey(), 9, "bt1 has minimum 9");

    bt1.Insert(10);
    AssertEqual(bt1.Minimum() -> GetKey(), 9, "bt1 has minimum 9");

    bt1.Insert(5);
    AssertEqual(bt1.Minimum() -> GetKey(), 5, "bt1 has minimum 5");

    bt1.Insert(4);
    AssertEqual(bt1.Minimum() -> GetKey(), 4, "bt1 has minimum 4");
}

void
TestBinaryTreeSuccessor()
{
    BinaryTree<int> bt1(10);
    Assert(bt1.Successor(bt1.Search(10)) == nullptr, "bt1: node 10 has no successor");

    bt1.Insert(11);
    AssertEqual((bt1.Successor(bt1.Search(10)) -> GetKey()), 11, "bt1: node 10 has successor 11");
    Assert(bt1.Successor(bt1.Search(11)) == nullptr, "bt1: node 11 has no successor");

    bt1.Insert(12);
    AssertEqual((bt1.Successor(bt1.Search(10)) -> GetKey()), 11, "bt1: node 10 has successor 11");
    AssertEqual((bt1.Successor(bt1.Search(11)) -> GetKey()), 12, "bt1: node 11 has successor 12");
    Assert(bt1.Successor(bt1.Search(12)) == nullptr, "bt1: node 12 has no successor");

    bt1.Insert(9);
    AssertEqual((bt1.Successor(bt1.Search(10)) -> GetKey()), 11, "bt1: node 10 has successor 11");
    AssertEqual((bt1.Successor(bt1.Search(11)) -> GetKey()), 12, "bt1: node 11 has successor 12");

    AssertEqual((bt1.Successor(bt1.Search(9)) -> GetKey()), 10, "bt1: node 9 has successor 10");
    Assert(bt1.Successor(bt1.Search(12)) == nullptr, "bt1: node 12 has no successor");

    bt1.Insert(10);
    AssertEqual((bt1.Successor(bt1.Search(10)) -> GetKey()), 11, "bt1: node 10 has successor 11");
    AssertEqual((bt1.Successor(bt1.Search(11)) -> GetKey()), 12, "bt1: node 11 has successor 12");
    AssertEqual((bt1.Successor(bt1.Search(9)) -> GetKey()), 10, "bt1: node 9 has successor 10");
    Assert(bt1.Successor(bt1.Search(12)) == nullptr, "bt1: node 12 has no successor");

    bt1.Insert(5);
    AssertEqual((bt1.Successor(bt1.Search(10)) -> GetKey()), 11, "bt1: node 10 has successor 11");
    AssertEqual((bt1.Successor(bt1.Search(11)) -> GetKey()), 12, "bt1: node 11 has successor 12");
    AssertEqual((bt1.Successor(bt1.Search(9)) -> GetKey()), 10, "bt1: node 9 has successor 10");
    AssertEqual((bt1.Successor(bt1.Search(5)) -> GetKey()), 9, "bt1 : node 5 has successor 9");
    Assert(bt1.Successor(bt1.Search(12)) == nullptr, "bt1: node 12 has no successor");


    bt1.Insert(7);
    AssertEqual((bt1.Successor(bt1.Search(10)) -> GetKey()), 11, "bt1: node 10 has successor 11");
    AssertEqual((bt1.Successor(bt1.Search(11)) -> GetKey()), 12, "bt1: node 11 has successor 12");
    AssertEqual((bt1.Successor(bt1.Search(9)) -> GetKey()), 10, "bt1: node 9 has successor 10");
    AssertEqual((bt1.Successor(bt1.Search(5)) -> GetKey()), 7, "bt1 : node 5 has successor 7");
    AssertEqual((bt1.Successor(bt1.Search(7)) -> GetKey()), 9, "bt1 : node 7 has successor 9");
    Assert(bt1.Successor(bt1.Search(12)) == nullptr, "bt1: node 12 has no successor");

}

void
TestBinaryTreePredecessor()
{
    BinaryTree<int> bt1(10);
    Assert(bt1.Predecessor(bt1.Search(10)) == nullptr, "bt1: node 10 has no predecessor");

    bt1.Insert(11);
    AssertEqual((bt1.Predecessor(bt1.Search(11)) -> GetKey()), 10, "bt1: node 11 has predecessor 10");
    Assert(bt1.Predecessor(bt1.Search(10)) == nullptr, "bt1: node 10 has no predecessor");

    bt1.Insert(12);
    AssertEqual((bt1.Predecessor(bt1.Search(12)) -> GetKey()), 11, "bt1: node 12 has Ppedecessor 11");
    AssertEqual((bt1.Predecessor(bt1.Search(11)) -> GetKey()), 10, "bt1: node 11 has predecessor 10");
    Assert(bt1.Predecessor(bt1.Search(10)) == nullptr, "bt1: node 10 has no predecessor");

    bt1.Insert(8);
    AssertEqual((bt1.Predecessor(bt1.Search(12)) -> GetKey()), 11, "bt1: node 12 has predecessor 11");
    AssertEqual((bt1.Predecessor(bt1.Search(11)) -> GetKey()), 10, "bt1: node 11 has predecessor 10");
    AssertEqual((bt1.Predecessor(bt1.Search(10)) -> GetKey()), 8, "bt1: node 10 has predecessor 8");
    Assert(bt1.Predecessor(bt1.Search(8)) == nullptr, "bt1: node 8 has no predecessor");

    bt1.Insert(9);
    AssertEqual((bt1.Predecessor(bt1.Search(12)) -> GetKey()), 11, "bt1: node 12 has predecessor 11");
    AssertEqual((bt1.Predecessor(bt1.Search(11)) -> GetKey()), 10, "bt1: node 11 has predecessor 10");
    AssertEqual((bt1.Predecessor(bt1.Search(10)) -> GetKey()), 9, "bt1: node 10 has predecessor 9s");
    AssertEqual((bt1.Predecessor(bt1.Search(9)) -> GetKey()), 8, "bt1: node 9 has predecessor 8");
    Assert(bt1.Predecessor(bt1.Search(8)) == nullptr, "bt1: node 8 has no predecessor");

    bt1.Insert(5);
    AssertEqual((bt1.Predecessor(bt1.Search(12)) -> GetKey()), 11, "bt1: node 12 has predecessor 11");
    AssertEqual((bt1.Predecessor(bt1.Search(11)) -> GetKey()), 10, "bt1: node 11 has predecessor 10");
    AssertEqual((bt1.Predecessor(bt1.Search(10)) -> GetKey()), 9, "bt1: node 10 has predecessor 9s");
    AssertEqual((bt1.Predecessor(bt1.Search(8)) -> GetKey()), 5, "bt1: node 8 has predecessor 5");
    Assert(bt1.Predecessor(bt1.Search(5)) == nullptr, "bt1: node 5 has no predecessor");


    bt1.Insert(7);
    AssertEqual((bt1.Predecessor(bt1.Search(12)) -> GetKey()), 11, "bt1: node 12 has predecessor 11");
    AssertEqual((bt1.Predecessor(bt1.Search(11)) -> GetKey()), 10, "bt1: node 11 has predecessor 10");
    AssertEqual((bt1.Predecessor(bt1.Search(10)) -> GetKey()), 9, "bt1: node 10 has predecessor 9s");
    AssertEqual((bt1.Predecessor(bt1.Search(8)) -> GetKey()), 7, "bt1: node 8 has predecessor 7");
    AssertEqual((bt1.Predecessor(bt1.Search(7)) -> GetKey()), 5, "bt1: node 7 has predecessor 5");
    Assert(bt1.Predecessor(bt1.Search(5)) == nullptr, "bt1: node 5 has no predecessor");
 }

void
TestBinaryTreeDelete()
{
    { // deleted node is the root
        BinaryTree<int> bt1(10);
        bt1.Delete(bt1.Search(10));
        AssertEqual(bt1.NodesCount(), 0, "bt1 is empty");
        Assert(bt1.GetRoot() == nullptr, "bt1 is empty");
    }

    { // deleted node is a leaf
        BinaryTree<int> bt2;
        bt2.Insert(10);
        bt2.Insert(20);
        bt2.Insert(5);

        bt2.Delete(bt2.Search(5));
        AssertEqual(bt2.NodesCount(), 2, "bt2 has 2 nodes");
        Assert(bt2.Search(10) -> GetLessNode() == nullptr, "bt2: node 10 has no less node");
        bt2.Delete(bt2.Search(20));
        AssertEqual(bt2.NodesCount(), 1, "bt2 has 1 node");
        Assert(bt2.Search(10) -> GetLessNode() == nullptr, "bt2: node 10 has no less node");
        Assert(bt2.Search(10) -> GetGreaterNode() == nullptr, "bt2: node 10 has no greater node");
    }

    { // deleted node has only one child node
        BinaryTree<int> bt3(10);
        bt3.Insert(20);
        bt3.Insert(5);
        bt3.Insert(8);
        bt3.Insert(15);
        bt3.Insert(17);
        bt3.Insert(7);

        bt3.Delete(bt3.Search(8));
        AssertEqual(bt3.NodesCount(), 6, "bt3 has 6 nodes");
        Assert(bt3.Search(7) -> GetParentNode() == bt3.Search(5), "bt3: node 7 has new parent 5");
        Assert(bt3.Search(5) -> GetGreaterNode() == bt3.Search(7), "bt3: node 5 has new greater node 7");

        bt3.Delete(bt3.Search(15));
        AssertEqual(bt3.NodesCount(), 5, "bt3 has 5 nodes");
        Assert(bt3.Search(17) -> GetParentNode() == bt3.Search(20), "bt3: node 17 has new parent 20");
        Assert(bt3.Search(20) -> GetLessNode() == bt3.Search(17), "bt3: node 20 has new less node 17");

        bt3.Delete(bt3.Search(20));
        AssertEqual(bt3.NodesCount(), 4, "bt3 has 4 nodes");
        Assert(bt3.Search(17) -> GetParentNode() == bt3.Search(10), "bt3: node 17 has new parent 10");
        Assert(bt3.Search(10) -> GetGreaterNode() == bt3.Search(17), "bt3: node 10 has new greater node 17");

        bt3.Delete(bt3.Search(5));
        AssertEqual(bt3.NodesCount(), 3, "bt3 has 3 nodes");
        Assert(bt3.Search(7) -> GetParentNode() == bt3.Search(10), "bt3: node 7 has new parent 10");
        Assert(bt3.Search(10) -> GetLessNode() == bt3.Search(7), "bt3: node 10 has new less node 7");
    }

    { // deleted node has both less and greater nodes
        BinaryTree<int> bt4;
        bt4.Insert(10);
        bt4.Insert(20);
        bt4.Insert(5);
        bt4.Insert(15);
        bt4.Insert(13);
        bt4.Insert(17);
        bt4.Insert(16);
        bt4.Insert(18);
        bt4.Insert(19);

        bt4.Delete(bt4.Search(17));
        AssertEqual(bt4.NodesCount(), 8, "bt4 has 8 nodes");
        Assert(bt4.Search(18) -> GetParentNode() == bt4.Search(15), "bt4: node 18 has new parent 15");
        Assert(bt4.Search(16) -> GetParentNode() == bt4.Search(18), "bt4: node 16 has new parent 18");
        Assert(bt4.Search(15) -> GetGreaterNode() == bt4.Search(18), "bt4: node 15 has new greater node 18");
        Assert(bt4.Search(18) -> GetLessNode() == bt4.Search(16), "bt4: node 18 has new less node 16");

        bt4.Insert(17);
        bt4.Delete(bt4.Search(15));
        AssertEqual(bt4.NodesCount(), 8, "bt4 has 8 nodes");
        Assert(bt4.Search(16) -> GetParentNode() == bt4.Search(20), "bt4: node 16 has new parent 20");
        Assert(bt4.Search(17) -> GetParentNode() == bt4.Search(18), "bt4: node 17 has new parent 18");
        Assert(bt4.Search(13) -> GetParentNode() == bt4.Search(16), "bt4: node 13 has new parent 16");
        Assert(bt4.Search(16) -> GetLessNode() == bt4.Search(13), "bt4: node 16 has new less node 13");
        Assert(bt4.Search(16) -> GetGreaterNode() == bt4.Search(18), "bt4: node 16 has new greater node 18");
        Assert(bt4.Search(16) -> GetLessNode() == bt4.Search(13), "bt4: node 16 has new less node 13");
        Assert(bt4.Search(16) -> GetGreaterNode() == bt4.Search(18), "bt4: node 16 has new greater node 18");
        Assert(bt4.Search(18) -> GetLessNode() == bt4.Search(17), "bt4: node 18 has new less node 17");

    }
}

void
TestBinaryTreeInOrderTraversal()
{
    BinaryTree<int> bt;
    bt.Insert(10);
    bt.Insert(14);
    bt.Insert(20);
    bt.Insert(6);
    bt.Insert(1);
    bt.Insert(12);
    bt.Insert(16);
    bt.Insert(4);

    std::vector<int> output;
    bt.InOrderTraversal(output);
    AssertEqual(output, std::vector<int>({1, 4, 6, 10, 12, 14, 16, 20}), "");
}

void
TestBinaryTreePreOrderTraversal()
{
    BinaryTree<int> bt;
    bt.Insert(10);
    bt.Insert(14);
    bt.Insert(20);
    bt.Insert(6);
    bt.Insert(1);
    bt.Insert(12);
    bt.Insert(16);
    bt.Insert(4);

    std::vector<int> output;
    bt.PreOrderTraversal(output);
    AssertEqual(output, std::vector<int>({10, 6, 1, 4, 14, 12, 20, 16}), "");
}

void
TestBinaryTreePostOrderTraversal()
{
    BinaryTree<int> bt;
    bt.Insert(10);
    bt.Insert(14);
    bt.Insert(20);
    bt.Insert(6);
    bt.Insert(1);
    bt.Insert(12);
    bt.Insert(16);
    bt.Insert(4);

    std::vector<int> output;
    bt.PostOrderTraversal(output);
    AssertEqual(output, std::vector<int>({4, 1, 6, 12, 16, 20, 14, 10}), "");
}

void
TestBinaryTreeLevelTraversal()
{
    BinaryTree<int> bt;
    bt.Insert(10);
    bt.Insert(14);
    bt.Insert(20);
    bt.Insert(6);
    bt.Insert(1);
    bt.Insert(12);
    bt.Insert(16);
    bt.Insert(4);

    std::vector<int> output;
    bt.LevelTraversal(output);
    AssertEqual(output, std::vector<int>({10, 6, 14, 1, 12, 20, 4, 16}), "");
}

void
TestBinaryTreeNodesCount()
{
    BinaryTree<int> bt;
    AssertEqual(bt.NodesCount(), 0, "bt has 0 nodes");

    bt.Insert(10);
    AssertEqual(bt.NodesCount(), 1, "bt has 1 nodes");

    bt.Insert(12);
    AssertEqual(bt.NodesCount(), 2, "bt has 2 nodes");

    bt.Insert(8);
    AssertEqual(bt.NodesCount(), 3, "bt has 3 nodes");

    bt.Insert(14);
    AssertEqual(bt.NodesCount(), 4, "bt has 4 nodes");

    bt.Insert(9);
    AssertEqual(bt.NodesCount(), 5, "bt has 5 nodes");
}

void
TestBinaryTreeHeight()
{
    BinaryTree<int> bt;
    AssertEqual(bt.Height(), 0, "bt has height 0");

    bt.Insert(10);
    AssertEqual(bt.Height(), 1, "bt has height 1");

    bt.Insert(12);
    AssertEqual(bt.Height(), 2, "bt has height 2 after inserting 12");

    bt.Insert(8);
    AssertEqual(bt.Height(), 2, "bt has height 2 after inserting 8");

    bt.Insert(14);
    AssertEqual(bt.Height(), 3, "bt has height 3");

    bt.Insert(9);
    AssertEqual(bt.Height(), 3, "bt has height 3");

    bt.Insert(1);
    AssertEqual(bt.Height(), 3, "bt has height 3");

    bt.Insert(20);
    AssertEqual(bt.Height(), 4, "bt has height 4");
}

void
TestBinaryTreeClear()
{
    BinaryTree<int> bt;
    bt.Clear();
    AssertEqual(bt.NodesCount(), 0, "bt has no nodes");
    Assert(bt.GetRoot() == nullptr, "bt is empty 1");

    bt.Insert(10);
    bt.Insert(12);
    bt.Insert(8);
    bt.Insert(14);
    bt.Insert(16);
    bt.Insert(18);
    bt.Insert(15);
    bt.Insert(9);
    bt.Insert(6);
    bt.Clear();
    AssertEqual(bt.NodesCount(), 0, "bt has no nodes");
    Assert(bt.GetRoot() == nullptr, "bt is empty 2");
}

void
TestBinaryTree()
{
    TestRunner tr;

    tr.RunTest(TestBinaryTreeConstructor, "TestBinaryTreeConstructor");
    tr.RunTest(TestBinaryTreeInsert, "TestBinaryTreeInsert");
    tr.RunTest(TestBinaryTreeSearch, "TestBinaryTreeSearch");
    tr.RunTest(TestBinaryTreeMaximum, "TestBinaryTreeMaximum");
    tr.RunTest(TestBinaryTreeMinimum, "TestBinaryTreeMinimum");
    tr.RunTest(TestBinaryTreeSuccessor, "TestBinaryTreeSuccessor");
    tr.RunTest(TestBinaryTreePredecessor, "TestBinaryTreePredecessor");
    tr.RunTest(TestBinaryTreePreOrderTraversal, "TestBinaryTreePreOrderTraversal");
    tr.RunTest(TestBinaryTreeInOrderTraversal, "TestBinaryTreeInOrderTraversal");
    tr.RunTest(TestBinaryTreePostOrderTraversal, "TestBinaryTreePostOrderTraversal");
    tr.RunTest(TestBinaryTreeLevelTraversal, "TestBinaryTreeLevelTraversal");
    tr.RunTest(TestBinaryTreeNodesCount, "TestBinaryTreeNodesCount");
    tr.RunTest(TestBinaryTreeHeight, "TestBinaryTreeHeight");
    tr.RunTest(TestBinaryTreeNodesCount, "TestBinaryTreeNodesCount");
    tr.RunTest(TestBinaryTreeClear, "TestBinaryTreeClear");
    tr.RunTest(TestBinaryTreeDelete, "TestBinaryTreeDelete");
}
