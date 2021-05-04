//
//  tests.cpp
//  Singly-linked List
//
//  Created by Лабутин Антон Александрович on 15.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include "test_runner.hpp"
#include "tests.hpp"
#include "list.hpp"
#include "list_node.hpp"

void
TestListConstructor()
{
    List<int> l1;
    List<double> l2(3, 2.0);

    AssertEqual(l1.GetLen(), 0, "List l1 is empty");
    AssertEqual(l2.GetLen(), 3, "List l2 has len 3");

    for (ListNode<double> *node = l2.GetHead(); node != nullptr; node = node -> GetNextNode()) {
        AssertEqual(node -> GetKey(), 2.0, "List l2: all elements are 2.0");
    }

    try {
        List<int> l3(0, 1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }
}

void
TestListCopyConstructor()
{
    List<int> l1(3, 4);
    List<int> l2(l1);

    AssertEqual(l2.GetLen(), 3, "List l2 has len 3");

    for (ListNode<int> *node = l2.GetHead(); node != nullptr; node = node -> GetNextNode()) {
        AssertEqual(node -> GetKey(), 4, "List l2: all elements are 4");
    }

    List<int> l3;
    List<int> l4(l3);

    AssertEqual(l4.GetLen(), 0, "List l4 is empty");
}

void
TestListOperatorEqual()
{
    List<int> l1;
    List<int> l2(1, 2);
    List<int> l3(2, 3);
    List<int> l4(3, 4);

    List<int> assign_list;
    assign_list = l1;
    AssertEqual(assign_list.GetLen(), 0, "List l1 is empty");

    assign_list = l2;
    AssertEqual(assign_list.GetLen(), 1, "List l2 is has len 1}");
    AssertEqual(assign_list.GetHead() -> GetKey(), 2, "List l1 is {2}");

    assign_list = l3;
    AssertEqual(assign_list.GetLen(), 2, "List l3 is has len 2}");

    for (ListNode<int> *node = assign_list.GetHead(); node != nullptr; node = node -> GetNextNode()) {
        AssertEqual(node -> GetKey(), 3, "List l3: all elements are 3");
    }



    assign_list = l4;
    AssertEqual(assign_list.GetLen(), 3, "List l4 is has len 3}");

    for (ListNode<int> *node = assign_list.GetHead(); node != nullptr; node = node -> GetNextNode()) {
        AssertEqual(node -> GetKey(), 4, "List l4: all elements are 4");
    }

    assign_list = l2;
    AssertEqual(assign_list.GetLen(), 1, "List l2 is has len 1}");

    for (ListNode<int> *node = assign_list.GetHead(); node != nullptr; node = node -> GetNextNode()) {
        AssertEqual(node -> GetKey(), 2, "List l2: all elements are 2");
    }

    assign_list = l1;
    AssertEqual(assign_list.GetLen(), 0, "List l1 is empty}");
}

void
TestListPushFront()
{
    List<int> l1;
    l1.PushFront(1);
    AssertEqual(l1.GetLen(), 1, "List l1 has len 1");
    AssertEqual(l1.GetHead() -> GetKey(), 1, "List l1 is {1}");

    l1.PushFront(2);
    AssertEqual(l1.GetLen(), 2, "List l1 has len 2");
    ListNode<int> *currentNode = l1.GetHead();
    AssertEqual(currentNode -> GetKey(), 2, "List l1 is {2, 1}");
    currentNode = currentNode -> GetNextNode();
    AssertEqual(currentNode -> GetKey(), 1, "List l1 is {2, 1}");

    List<int> l2(2, 0);
    l2.PushFront(1);
    AssertEqual(l2.GetLen(), 3, "List l2 has len 3");
    currentNode = l2.GetHead();
    AssertEqual(currentNode -> GetKey(), 1, "List l2 is {1, 0, 0}");
    currentNode = currentNode -> GetNextNode();
    AssertEqual(currentNode -> GetKey(), 0, "List l2 is {1, 0, 0}");
    currentNode = currentNode -> GetNextNode();
    AssertEqual(currentNode -> GetKey(), 0, "List l2 is {1, 0, 0}");
}

void
TestListPushBack()
{
    List<int> l1;
    l1.PushBack(1);
    AssertEqual(l1.GetLen(), 1, "List l1 has len 1");
    AssertEqual(l1.GetHead() -> GetKey(), 1, "List l1 is {1}");

    l1.PushBack(2);
    AssertEqual(l1.GetLen(), 2, "List l1 has len 2");
    ListNode<int> *currentNode = l1.GetHead();
    AssertEqual(currentNode -> GetKey(), 1, "List l1 is {1, 2}");
    currentNode = currentNode -> GetNextNode();
    AssertEqual(currentNode -> GetKey(), 2, "List l1 is {1, 2}");

    List<int> l2(2, 0);
    l2.PushBack(1);
    AssertEqual(l2.GetLen(), 3, "List l2 has len 3");
    currentNode = l2.GetHead();
    AssertEqual(currentNode -> GetKey(), 0, "List l2 is {0, 0, 1}");
    currentNode = currentNode -> GetNextNode();
    AssertEqual(currentNode -> GetKey(), 0, "List l2 is {0, 0, 1}");
    currentNode = currentNode -> GetNextNode();
    AssertEqual(currentNode -> GetKey(), 1, "List l2 is {0, 0, 1}");
}

void
TestListTopFront()
{
    List<int> l1;
    try {
        l1.TopFront();
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    List<int> l2(1, 2);
    AssertEqual(l2.TopFront(), 2, "List l2 is {2}");
    AssertEqual(l2.GetLen(), 1, "List l2 has len 1");

    List<int> l3(2, 3);
    AssertEqual(l3.TopFront(), 3, "List l3 is {3, 3}");
    AssertEqual(l3.GetLen(), 2, "List l3 has len 2");

    l3.PushBack(4);
    AssertEqual(l3.TopFront(), 3, "List l3 is {3, 3, 4}");

    l3.PushFront(5);
    AssertEqual(l3.TopFront(), 5, "List l3 is {5, 3, 3, 4}");

    const List<int> l4(3, 4);
    AssertEqual(l4.TopFront(), 4, "Const list l4 is {4, 4, 4}");
}

void
TestListTopBack()
{
    List<int> l1;
    try {
        l1.TopBack();
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    List<int> l2(1, 2);
    AssertEqual(l2.TopBack(), 2, "List l2 is {2}");
    AssertEqual(l2.GetLen(), 1, "List l2 has len 1");

    List<int> l3(2, 3);
    AssertEqual(l3.TopBack(), 3, "List l3 is {3, 3}");
    AssertEqual(l3.GetLen(), 2, "List l3 has len 2");

    l3.PushBack(4);
    AssertEqual(l3.TopBack(), 4, "List l3 is {3, 3, 4}");

    l3.PushFront(5);
    AssertEqual(l3.TopBack(), 4, "List l3 is {5, 3, 3, 4}");

    const List<int> l4(3, 4);
    AssertEqual(l4.TopBack(), 4, "Const list l4 is {4, 4, 4}");
}

void
TestListPopFront()
{
    List<int> l1;
    try {
        l1.PopFront();
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(1);
    l1.PopFront();
    AssertEqual(l1.GetLen(), 0, "List l1 is empty");

    l1.PushBack(3);
    l1.PushBack(2);
    l1.PopFront();
    AssertEqual(l1.GetLen(), 1, "List l1 has len 1");
    AssertEqual(l1.TopFront(), 2, "List l1 is {2}");

    l1.PushBack(4);
    l1.PushBack(5);
    l1.PopFront();
    AssertEqual(l1.GetLen(), 2, "List l1 has len 2");
    AssertEqual(l1.TopFront(), 4, "List l1 is {4, 5}");
    AssertEqual(l1.TopBack(), 5, "List l1 is {4, 5}");

}

void
TestListPopBack()
{
    List<int> l1;
    try {
        l1.PopBack();
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(1);
    l1.PopBack();
    AssertEqual(l1.GetLen(), 0, "List l1 is empty");

    l1.PushBack(3);
    l1.PushBack(2);
    l1.PopBack();
    AssertEqual(l1.GetLen(), 1, "List l1 has len 1");
    AssertEqual(l1.TopFront(), 3, "List l1 is {3}");

    l1.PushBack(4);
    l1.PushBack(5);
    l1.PopBack();
    AssertEqual(l1.GetLen(), 2, "List l1 has len 2");
    AssertEqual(l1.TopFront(), 3, "List l1 is {3, 4}");
    AssertEqual(l1.TopBack(), 4, "List l1 is {3, 4}");
}

void
TestListFind()
{
    List<int> l1;
    try {
        l1.Find(1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);

    Assert(l1.Find(1), "List l1 is {1, 2, 3}");
    Assert(l1.Find(2), "List l1 is {1, 2, 3}");
    Assert(l1.Find(3), "List l1 is {1, 2, 3}");
    Assert(! l1.Find(0), "List l1 is {1, 2, 3}");
    Assert(! l1.Find(5), "List l1 is {1, 2, 3}");
}

void
TestListErase()
{
    List<int> l1;
    try {
        l1.Erase(1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);

    try {
        l1.Erase(5);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.Erase(2);
    AssertEqual(l1.GetLen(), 2, "List l1 has len 2");
    AssertEqual(l1.TopFront(), 1, "List l1 is {1, 3}");
    AssertEqual(l1.TopBack(), 3, "List l1 is {1, 3}");

    l1.Erase(1);
    AssertEqual(l1.GetLen(), 1, "List l1 has len 1");
    AssertEqual(l1.TopFront(), 3, "List l1 is {3}");

    l1.Erase(3);
    AssertEqual(l1.GetLen(), 0, "List l1 is empty");
}

void
TestListEmpty()
{
    List<int> l1;
    Assert(l1.Empty(), "List l1 is empty");

    l1.PushFront(1);
    Assert(! l1.Empty(), "List l1 is not empty");
}

void
TestListAddBefore()
{
    List<int> l1(1, 2);
    try {
        l1.AddBefore(nullptr, 1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PopBack();
    try {
        ListNode<int> *node = new ListNode<int>(1);
        l1.AddBefore(node, 1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(1);
    try {
        ListNode<int> *node = new ListNode<int>(1);
        l1.AddBefore(node, 1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(2);
    l1.AddBefore(l1.GetHead(), 3);
    AssertEqual(l1.GetLen(), 3, "List l1 has len 3");
    AssertEqual(l1.TopFront(), 3, "List l1 has 1st element = 3");

    ListNode<int> *node = l1.GetHead();
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 1, "List l1 has second element = 1");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 2, "List l1 has 3d element = 2");

    node = l1.GetKeyPos(1);
    l1.AddBefore(node, 4);
    AssertEqual(l1.GetLen(), 4, "List l1 has len 4");
    AssertEqual(l1.TopFront(), 3, "List l1 is {3, 4, 1, 2}");
    node = l1.GetHead();
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 4, "List l1 is {3, 4, 1, 2}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 1, "List l1 is {3, 4, 1, 2}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 2, "List l1 is {3, 4, 1, 2}");

    l1.AddBefore(node, 5);
    AssertEqual(l1.GetLen(), 5, "List l1 has len 5");
    AssertEqual(l1.TopFront(), 3, "List l1 is {3, 4, 1, 5, 2}");
    node = l1.GetHead();
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 4, "List l1 is {3, 4, 1, 5, 2}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 1, "List l1 is {3, 4, 1, 5, 2}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 5, "List l1 is {3, 4, 1, 5, 2}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 2, "List l1 is {3, 4, 1, 5, 2}");
}

void
TestListAddAfter()
{
    List<int> l1(1, 2);
    try {
        l1.AddAfter(nullptr, 1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PopBack();
    try {
        ListNode<int> *node = new ListNode<int>(1);
        l1.AddAfter(node, 1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(1);
    try {
        ListNode<int> *node = new ListNode<int>(1);
        l1.AddAfter(node, 1);
    } catch(std::runtime_error& rte) {
        std::cout << rte.what() << std::endl;
    }

    l1.PushBack(2);
    l1.AddAfter(l1.GetHead(), 3);
    AssertEqual(l1.GetLen(), 3, "List l1 has len 3");
    AssertEqual(l1.TopFront(), 1, "List l1 has 1st element = 1");

    ListNode<int> *node = l1.GetHead();
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 3, "List l1 has second element = 3");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 2, "List l1 has 3d element = 2");

    node = l1.GetKeyPos(3);
    l1.AddAfter(node, 4);
    AssertEqual(l1.GetLen(), 4, "List l1 has len 4");
    AssertEqual(l1.TopFront(), 1, "List l1 is {1, 3, 4, 2}");
    node = l1.GetHead();
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 3, "List l1 is {1, 3, 4, 2}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 4, "List l1 is {1, 3, 4, 2}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 2, "List l1 is {1, 3, 4, 2}");

    l1.AddAfter(node, 5);
    AssertEqual(l1.GetLen(), 5, "List l1 has len 5");
    AssertEqual(l1.TopFront(), 1, "List l1 is {1, 3, 4, 2, 5}");
    node = l1.GetHead();
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 3, "List l1 is {1, 3, 4, 2, 5}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 4, "List l1 is {1, 3, 4, 2, 5}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 2, "List l1 is {1, 3, 4, 2, 5}");
    node = node -> GetNextNode();
    AssertEqual(node -> GetKey(), 5, "List l1 is {1, 3, 4, 2, 5}");
}

void
TestListGetLen()
{
    List<int> l1;
    AssertEqual(l1.GetLen(), 0, "List l1 is empty");

    l1.PushBack(1);
    AssertEqual(l1.GetLen(), 1, "List l1 has len 1}");

    l1.PushFront(2);
    AssertEqual(l1.GetLen(), 2, "List l1 has len 2}");

    l1.PopFront();
    AssertEqual(l1.GetLen(), 1, "List l1 has len 1}");

    l1.PopBack();
    AssertEqual(l1.GetLen(), 0, "List l1 is empty");
}

void
TestList()
{
    TestRunner tr;

    tr.RunTest(TestListConstructor, "TestListConstructor");
    tr.RunTest(TestListCopyConstructor, "TestListCopyConstructor");

    tr.RunTest(TestListPushFront, "TestListPushFront");
    tr.RunTest(TestListPushBack, "TestListPushBack");

    tr.RunTest(TestListOperatorEqual, "TestListOperatorEqual");

    tr.RunTest(TestListGetLen, "TestListGetLen");
    tr.RunTest(TestListEmpty, "TestListEmpty");

    tr.RunTest(TestListTopFront, "TestListTopFront");
    tr.RunTest(TestListTopBack, "TestListTopBack");

    tr.RunTest(TestListPopFront, "TestListPopFront");
    tr.RunTest(TestListPopBack, "TestListPopBack");
    tr.RunTest(TestListErase, "TestListErase");

    tr.RunTest(TestListFind, "TestListFind");

    tr.RunTest(TestListAddBefore, "TestListAddBefore");
    tr.RunTest(TestListAddAfter, "TestListAddAfter");
}
